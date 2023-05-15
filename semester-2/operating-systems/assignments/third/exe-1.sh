#!/bin/bash
echo -n "Enter file name: "
read filename

until [ -f $filename ]
do
:
done