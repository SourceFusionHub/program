#!/bin/bash

# Prompt the user to enter the directory path
read -p "Enter the directory path to list and sort files: " directory

# Check if the directory exists
if [ ! -d "$directory" ]; then
  echo "Directory not found: $directory"
  exit 1
fi

# Use 'ls' to list and sort files by modification date (-t: newest first)
sorted_files_with_dates=$(ls -lt "$directory")

# Display the sorted files with their modification dates
echo "List of files in $directory sorted by modification date:"
echo "$sorted_files_with_dates"
