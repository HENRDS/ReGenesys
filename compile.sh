#!/usr/bin/env bash
set -euo pipefail
shopt -s nullglob extglob

base_d="bin"
output_f="myregenesysapplication.out"
flags=( -fpermissive -fPIC -no-pie -std=c++11 )


echo "Compiling source files" 
for f in *.cpp; do
    fobj="$base_d/${f%.*}.o"
    if [ "$f" -nt "$fobj" ]
    then
        echo "Building $f => $fobj"
        g++ ${flags[@]} -c -o $fobj $f
    fi
done

echo "Linking object files to $output_f"
g++ ${flags[@]} "$base_d"/*.o parserBisonFlex/*.o -o "$output_f" 

echo "Compilation successfull"
