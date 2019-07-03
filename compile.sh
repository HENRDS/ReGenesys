#!/usr/bin/env bash
set -euo pipefail
shopt -s nullglob extglob nocasematch

base_d="bin"
if [[ ! $(uname -s) =~ Linux ]]; then 
    flags=( -fpermissive -fPIC -no-pie -std=c++11 )
else
    flags=( -fpermissive -fPIC -no-pie -std=c++11 )
fi

echo "Compiling source files" 
for f in *.cpp; do
    fobj="$base_d/${f%.*}.o"
    if [ "$f" -nt "$fobj" ]
    then
        echo "Building $f => $fobj"
        g++ ${flags[@]} -c -o $fobj $f
    fi
done

echo "Linking object files to myregenesysapplication.out"
g++ ${flags[@]} "$base_d"/*.o parserBisonFlex/*.o -o myregenesysapplication.out 

echo "Compilation successfull"
