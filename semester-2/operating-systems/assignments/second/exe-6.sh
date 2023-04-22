#!/bin/bash
echo -n "Enter birth DAY (dd): "
read day
echo -n "Enter birth MONTH (mm): "
read month
echo -n "Enter birth YEAR (yyyy): "
read year

# Convert user age to epoch time
eage=$(date --date=$month/$day/$year +"%s")
# Get current epoch
epoch=$(date +"%s")
# Calculate user age
age=$((($epoch-$eage)/31556926))

if [ $age -lt 12 ]
then
    echo "Hello little boy"
elif [ $age -ge 12 -a $age -lt 19 ]
then
    echo "Hello teenager"
elif [ $age -ge 19 -a $age -le 45 ]
then
    echo "Hello little mister"
elif [ $age -gt 45 ]
then
    echo "Hello mister"
fi