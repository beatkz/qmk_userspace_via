#!/bin/bash

# スクリプトと同じディレクトリに移動
cd "$(dirname "$0")"

# build_target.txtの各行を処理
# #で始まる行はスキップ
while IFS= read -r k; do
    # 空行と#で始まる行をスキップ
    [[ -z "$k" || "$k" =~ ^# ]] && continue
    
    echo "$k"
    bash mksymlink.sh "$k"
done < build_target_linux.txt
