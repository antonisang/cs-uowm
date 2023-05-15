#!/bin/bash

# Generate file
echo "Bill 12000
John 13200
Jenny 32100
George 32100
Helen 14000" > temp.txt

# Parse and process data
sum=0
count=0
for pay in $(cat temp.txt | awk '{print $2}')
do
sum=$(($sum + $pay))
count=$(($count + 1))
done

# Print result
echo $(($sum / $count))

# Cleanup
rm temp.txt