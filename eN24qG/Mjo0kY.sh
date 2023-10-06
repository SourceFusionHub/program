#!/bin/bash

# Check if the number of arguments is less than 1
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Get the file name from the first argument
FILE="$1"

# Check if the file is readable
if [ -r "$FILE" ]; then
    echo "$FILE is readable."
else
    echo "$FILE is not readable."
fi
