#!/bin/bash
if [ $# -eq 1 ]
then
    if [ -f $1 ]
    then
        echo "There is already a file named $1"
    else
        # Use "| head -n 2 | tail -n 1" to remove leading "\n" from "ls -l --sort=time | awk '{print $9}' "
        recent=$(ls -l --sort=time | awk '{print $9}' | head -n 2 | tail -n 1)
        cp $recent $1
    fi
else
    echo "Syntax Error: An incorrect number of parameters was provided"
fi