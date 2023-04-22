#!/bin/bash
hours=$(date +"%H")
minutes=$(date +"%M")

if [ $hours -le 12 ]
then
    echo "$hours:$minutes am"
else
    echo "$((hours%12)):$minutes pm"
fi