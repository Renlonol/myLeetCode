#/bin/bash

function _build()
{
    local files=$(find ./ -name Makefile)
    for file in $files
    do
        path=$(dirname $file)
        cd $path && make $1 -j  && cd -
    done
}

function _sub_build()
{
    if [ -n "$1" ]; then
        for dir in $1
        do
            if [ -e $dir ]; then
                cd $dir && make -j && cd -
            else
                echo "ERR: $dir not exist!"
            fi
        done
    fi
}

if [ -z "$1" ]; then
    _build
elif [ "$1" != "clean" ]; then
    _sub_build "$1"
elif [ "$1" = "clean" ]; then
    _build "clean"
fi



