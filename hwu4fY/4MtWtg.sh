#!/bin/bash

# Check if at least one argument (directory path) is provided
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

directory="$1"

# Check if the provided path is a directory
if [ ! -d "$directory" ]; then
    echo "Error: $directory is not a directory."
    exit 1
fi

# Navigate to the specified directory
cd "$directory" || exit

# Iterate through each .sh file in the directory
for file in *.sh; do
    if [ -f "$file" ]; then
        # Extract the timestamp from the filename
        timestamp=$(echo "$file" | grep -oE '[0-9]{14}')

        # If a timestamp is found, create a new filename by appending the timestamp
        if [ -n "$timestamp" ]; then
            new_name="${file%.sh}_$timestamp.sh"

            # Rename the file
            mv "$file" "$new_name"

            echo "Renamed: $file -> $new_name"
        else
            echo "No timestamp found in the filename: $file"
        fi
    fi
done

echo "Renaming complete."
