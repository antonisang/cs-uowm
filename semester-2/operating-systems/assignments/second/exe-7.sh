#!/bin/bash
if [ $# -eq 1 ]
then
    # -q silent mode, show no output
    # -w match only whole words 
    grep -q -w "$1" "/etc/passwd"
    if [ $? -eq 0 ]
    then
        echo "User $1 found"
    else
        echo "User not found"
    fi
else
    echo "Syntax Error: An incorrect number of parameters was provided"
fi
