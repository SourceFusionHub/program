#!/bin/bash

# Define the character constraints
lowercase="abcdefghijklmnopqrstuvwxyz"
uppercase="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
numbers="0123456789"
# optional to include special characters and modify particular characters maybe supported, you can comment using # before it
specialchars="!@#$%^&*()_-+=<>?" 

# Combine all the character sets
allchars="${lowercase}${uppercase}${numbers}${specialchars}"

# Function to generate a random password
generate_password() {
  length=$1
  password=""
  for ((i=0; i<length; i++)); do
    random_index=$((RANDOM % ${#allchars}))
    password="${password}${allchars:${random_index}:1}"
  done
  echo "$password"
}

# Prompt the user for desired password length
read -p "Enter the desired password length: " password_length

# Check if the input is numeric and greater than 0
if [[ ! $password_length =~ ^[0-9]+$ || $password_length -le 0 ]]; then
  echo "Invalid input. Please enter a positive numeric value for the password length."
  exit 1
fi

# Generate the random password
result=$(generate_password $password_length)

# Output the generated password
echo "Generated Password: $result"
