#!/bin/bash
if [ $# -eq 1 ]
then
    if [ -d $1 ]
    then
        echo "$1 is a directory"
    elif [ -f $1 ]
    then
        echo "$1 is a file"
    else
        echo "There is not such a file or directory"
    fi
else
    echo "Syntax Error: An incorrect number of parameters was provided"
fi