#!/bin/bash
echo -n "Give me a number: " 
read num
if [[ $num%2 -eq 0 ]]
then
    echo "The number in even"
else
    echo "The number is odd"
fi
