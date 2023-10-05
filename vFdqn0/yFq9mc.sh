#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <directory> <search_word>"
    exit 1
fi

search_directory="$1"
word_to_search="$2"

find "$search_directory" -type f -exec grep -l "$word_to_search" {} \;
