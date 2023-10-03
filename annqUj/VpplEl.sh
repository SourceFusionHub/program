#!/bin/bash
#Reading the input directory here

echo "Enter Directory Url"
read input_dir

echo "Enter Output File Name"
read output_video

cd "$input_dir"

# Run ffmpeg to convert images to video
ffmpeg -framerate 30 -pattern_type glob -i '*.jpg' -c:v libx264 -pix_fmt yuv420p "$output_video"

echo "Video conversion completed!"
