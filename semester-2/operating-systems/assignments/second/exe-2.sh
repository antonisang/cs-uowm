#!/bin/bash
filesCount=$(ls -l /etc | grep ^- | wc -l)
echo "Files in /etc directory: $filesCount"