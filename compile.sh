#!/usr/bin/env bash
set -euo pipefail
shopt -s nullglob extglob

base_d="bin"

echo "Compiling source files" 
for f in *.cpp; do
    fobj="$base_d/${f%.*}.o"
    if [ "$f" -nt "$fobj" ]
    then
        echo "Building $f => $fobj"
        g++ -fpermissive -fPIC -c -no-pie -std=c++11 -o $fobj $f
    fi
done

echo "Linking object files to myregenesysapplication.out"
g++ -fpermissive -no-pie -fPIC "$base_d"/*.o parserBisonFlex/*.o -std=c++11 -o myregenesysapplication.out 

echo "Compilation successfull"
