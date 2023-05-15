#!/bin/bash

while true
do

echo -e "--------------" 
echo "1. Get date
2. Get time
3. Get username
For exit press E or e
"
echo -n "Enter choice: "
read input

case $input in
    1) date "+%d/%m/%y";;
    2) date "+%H:%M:%S";;
    3) whoami;;
    E) exit;;
    e) exit;;
    *) echo "Unsupported range";;
esac
done