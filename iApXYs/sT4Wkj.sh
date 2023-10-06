#!/bin/bash

# Check for argument
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

DIRECTORY="$1"

# Check if directory exists
if [ ! -d "$DIRECTORY" ]; then
    echo "Error: Directory $DIRECTORY does not exist."
    exit 1
fi

# Find the oldest file
OLDEST_FILE=$(find "$DIRECTORY" -type f -print0 | xargs -0 ls -lt | tail -n 1 | awk '{print $NF}')

if [ -z "$OLDEST_FILE" ]; then
    echo "No files found in $DIRECTORY"
else
    echo "The oldest file in $DIRECTORY is: $OLDEST_FILE"
fi
