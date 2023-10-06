#!/bin/bash

# Function to calculate the surface area of a cylinder
calculate_surface_area() {
    local radius="$1"
    local height="$2"

    # Surface area formula for a cylinder: 2πr(r + h)
    local surface_area=$(echo "scale=2; 2 * 3.14159 * $radius * ($radius + $height)" | bc)

    echo "Surface area of the cylinder: $surface_area square units"
}

# Read radius and height from the user
read -p "Enter the radius of the cylinder (in units): " radius
read -p "Enter the height of the cylinder (in units): " height

# Check if input values are valid (non-negative numbers)
if ((radius < 0)) || ((height < 0)); then
    echo "Invalid input. Radius and height must be non-negative numbers."
else
    calculate_surface_area "$radius" "$height"
fi
