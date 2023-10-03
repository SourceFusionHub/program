#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Usage: $0 <directory_path>"
  exit 1
fi

directory_path="$1"

if [ ! -e "$directory_path" ]; then
  echo "Error: The specified path does not exist."
  exit 1
fi


echo "File/Directory Path | Permissions"

find "$directory_path" -exec stat -c "%n | %A" {} \;







bash
./generate_permissions_report.sh /path/to/your/directory
