#!/bin/bash
for (( i=1; i<=150; i++ )) 
do 
touch file$i.sh
echo $i > file$i.sh
done