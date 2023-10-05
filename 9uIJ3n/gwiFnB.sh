#!/bin/bash

# Function to generate a random password
generate_password() {
  # Define the character set from which the password will be generated
  characters="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+=<>?"

  # Password length (you can adjust this as needed)
  password_length=12

  # Use /dev/urandom to generate random bytes, then map them to the character set
  password=$(head -c$password_length /dev/urandom | tr -dc "$characters")

  echo "$password"
}

# Generate a random password and print it
random_password=$(generate_password)
echo "Random Password: $random_password"
