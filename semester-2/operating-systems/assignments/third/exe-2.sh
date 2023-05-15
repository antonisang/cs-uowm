#!/bin/bash
echo -n "Enter a number within the range of 20-30: "
read num

until [ $num -ge 20 -a $num -le 30 ]
do
echo "Value out of bound, please enter a value between 20 and 30"
echo -n "Enter a number within the range of 20-30: "
read num
done