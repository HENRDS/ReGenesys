#!/usr/bin/env bash

set -euo pipefail
shopt -s extglob nullglob
IFS=$'\n\t'
base_d="bin"

for f in *.cpp; do
    if [[ -f "$base_d/${f%.cpp}.o" ]]; then
        rm "$base_d/${f%.cpp}.o"
    fi
    echo "removing $base_d/${f%.cpp}.o"
done

echo "done cleaning"
