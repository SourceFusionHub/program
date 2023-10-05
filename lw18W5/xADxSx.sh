#!/bin/bash

# Function to convert Fahrenheit to Celsius
fahrenheit_to_celsius() {
  # Formula: (Fahrenheit - 32) * 5/9
  celsius=$(echo "scale=2; ($1 - 32) * 5/9" | bc)
  echo "$1°F is equal to $celsius°C"
}

# Check if an argument is provided
if [ $# -eq 1 ]; then
  fahrenheit_to_celsius "$1"
else
  echo "Usage: $0 <temperature in Fahrenheit>"
fi
