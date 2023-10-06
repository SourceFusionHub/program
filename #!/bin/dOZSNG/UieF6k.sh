#!/bin/bash

# Get the disk space usage information
disk_info=$(df -h)

# Print the disk space usage information
echo "Disk Space Usage:"
echo "$disk_info"
