if [ $# -eq 0 ]; then
    echo "Usage: $0 directory_name"
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "Error: Directory '$1' does not exist."
    exit 1
fi

dir_name=$(basename "$1")

tar -czf "$dir_name.tar.gz" "$1"

echo "Archive created: $dir_name.tar.gz"
