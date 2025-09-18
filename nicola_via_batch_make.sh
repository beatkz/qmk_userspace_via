#!/bin/bash

# 入力ファイル
INPUT_FILE="nicola_via_build_target.txt"

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

# ファイルから1行ずつ読み込む
while IFS= read -r line; do
    # 空行やコメント行（#で始まる）をスキップ
    if [[ -z "$line" || "$line" =~ ^# ]]; then
        continue
    fi

    # make コマンドを実行
    echo "make を実行中: $line"
    make $line:nicola_via
    if [[ $? -ne 0 ]]; then
        echo "エラー: make が失敗しました: $line"
        exit 1
    fi

    # 生成された .hex または .uf2 ファイルを移動
    for file in *.hex *.uf2; do
        if [[ -f "$file" ]]; then
            echo "ファイルを移動: $file -> $OUTPUT_DIR/"
            mv "$file" "$OUTPUT_DIR/"
            if [[ $? -ne 0 ]]; then
                echo "エラー: ファイルの移動に失敗しました: $file"
                exit 1
            fi
        fi
    done
done < "$INPUT_FILE"

echo "全ての make コマンドが正常に実行され、生成ファイルが $OUTPUT_DIR に移動されました。"
