#!/bin/bash
filesCount=$(ls -l . | awk '{print $9}' | grep ^k | wc -l)
echo "Files starting with "k" in the current directory: $filesCount"