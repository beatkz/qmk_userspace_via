#!/bin/bash

# QMK集約ディレクトリをここに入力
QMK_BASE="/d/OSSProj/kbfw/qmk"

# QMK ファームウェアのディレクトリ
QMK_FIRMWARE_LATEST="$QMK_BASE/latest"  # 最新版のリポジトリ
QMK_FIRMWARE_VERSIONED_BASE="$QMK_BASE/v" # 旧バージョン参照用リポジトリ

# 入力ファイル
INPUT_FILE="qmk_build_target.txt"

# 現在の日付を yyyy-mm-dd 形式で取得
DATE=$(date +%Y-%m-%d)

# 出力ディレクトリを作成（存在しない場合）
OUTPUT_DIR="./fwoutputs/$DATE"
mkdir -p "$OUTPUT_DIR"

# 入力ファイルが存在するか確認
if [[ ! -f "$INPUT_FILE" ]]; then
    echo "エラー: $INPUT_FILE が見つかりません。"
    exit 1
fi

# 最新版リポジトリの存在確認
if [[ ! -d "$QMK_FIRMWARE_LATEST" ]]; then
    echo "エラー: 最新版の QMK ファームウェアディレクトリ $QMK_FIRMWARE_LATEST が見つかりません。手動でクローンしてください。"
    exit 1
fi

# エラーを記録する配列
declare -a errors

# ファイルから1行ずつ読み込む
while IFS= read -r line; do
    # 空行やコメント行（#で始まる）をスキップ
    if [[ -z "$line" || "$line" =~ ^# ]]; then
        continue
    fi

    # 行を解析（カンマで分割）
    target=$(echo "$line" | cut -d',' -f1)
    version=$(echo "$line" | cut -s -d',' -f2)

    # バージョンが指定されていない場合は latest を使用
    if [[ -z "$version" ]]; then
        QMK_FIRMWARE_ROOT="$QMK_FIRMWARE_LATEST"
        version="latest"
    else
        QMK_FIRMWARE_ROOT="$QMK_FIRMWARE_VERSIONED_BASE$version"
    fi

    # QMK ファームウェアのディレクトリが存在しない場合、バージョン指定時のみクローン
    if [[ ! -d "$QMK_FIRMWARE_ROOT" && "$version" != "latest" ]]; then
        echo "QMK バージョン $version のディレクトリ $QMK_FIRMWARE_ROOT が見つかりません。クローンします..."
        git clone https://github.com/qmk/qmk_firmware.git --depth 1 --recurse-submodules --shallow-submodules -b "$version" "$QMK_FIRMWARE_ROOT"
        if [[ $? -ne 0 ]]; then
            echo "エラー: QMK バージョン $version のクローンに失敗しました。"
            errors+=("クローンエラー: $target ($version)")
            continue
        fi
    fi

    # QMK ファームウェアのディレクトリが存在するか確認
    if [[ ! -d "$QMK_FIRMWARE_ROOT" ]]; then
        echo "エラー: QMK ファームウェアディレクトリ $QMK_FIRMWARE_ROOT が見つかりません。"
        errors+=("ディレクトリエラー: $target ($version)")
        continue
    fi

    # make コマンドを実行
    echo "makeコマンド実行中： $target (QMK バージョン: $version)"
    make "$target" QMK_FIRMWARE_ROOT="$QMK_FIRMWARE_ROOT"
    if [[ $? -ne 0 ]]; then
        errors+=("$target ($version)")
    fi

    # 生成された .hex または .uf2 ファイルを移動
    for file in "$QMK_FIRMWARE_ROOT"/*.hex "$QMK_FIRMWARE_ROOT"/*.uf2; do
        if [[ -f "$file" ]]; then
            echo "ファイルを移動: $file -> $OUTPUT_DIR/"
            mv "$file" "$OUTPUT_DIR/"
            if [[ $? -ne 0 ]]; then
                errors+=("ファイル移動失敗: $file ($version)")
            fi
        fi
    done
done < "$INPUT_FILE"

# エラー結果の表示
if [[ ${#errors[@]} -eq 0 ]]; then
    echo "全ての make コマンドが正常に実行され、生成ファイルが $OUTPUT_DIR に移動されました。"
else
    echo "以下のターゲットでエラーが発生しました:"
    for error in "${errors[@]}"; do
        echo "  - $error"
    done
    exit 1
fi
