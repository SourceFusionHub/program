#!/bin/bash

# Get the latitude and longitude of the first point from the user.
echo "Enter the latitude of the first point:"
read lat1
echo "Enter the longitude of the first point:"
read lon1

# Get the latitude and longitude of the second point from the user.
echo "Enter the latitude of the second point:"
read lat2
echo "Enter the longitude of the second point:"
read lon2

# Calculate the distance between the two points using the Haversine formula.
distance=$(echo "2 * asin(sqrt(pow(sin((($lat2 - $lat1) / 2)), 2) + cos($lat1) * cos($lat2) * pow(sin((($lon2 - $lon1) / 2)), 2)))" | bc)

# Print the distance to the console.
echo "The distance between the two points is $distance kilometers."
