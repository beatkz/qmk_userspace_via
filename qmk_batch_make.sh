#!/bin/bash

# 入力ファイル
INPUT_FILE="qmk_build_target.txt"

# 現在の日付を yyyy-mm-dd 形式で取得
DATE=$(date +%Y-%m-%d)

# 出力ディレクトリを作成（存在しない場合）
OUTPUT_DIR="./fwoutputs/$DATE"
mkdir -p "$OUTPUT_DIR"

# ファイルが存在するか確認
if [[ ! -f "$INPUT_FILE" ]]; then
    echo "エラー: $INPUT_FILE が見つかりません。"
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

    # make コマンドのターゲットを決定
    target="$line"

    # make コマンドを実行
    echo makeコマンド実行中： $target
    make $target
    if [[ $? -ne 0 ]]; then
        errors+=("$target")
    fi

    # 生成された .hex または .uf2 ファイルを移動
    for file in *.hex *.uf2; do
        if [[ -f "$file" ]]; then
            echo "ファイルを移動: $file -> $OUTPUT_DIR/"
            mv "$file" "$OUTPUT_DIR/"
            if [[ $? -ne 0 ]]; then
                errors+=("ファイル移動失敗: $file")
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
