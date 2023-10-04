#!/bin/bash

# Array of quotes
quotes=("Quote 1" "Quote 2" "Quote 3" "Quote 4" "Quote 5")

# Get the number of quotes
num_quotes=${#quotes[@]}

# Generate a random index
random_index=$((RANDOM % num_quotes))

# Get the random quote
random_quote="${quotes[$random_index]}"

# Print the random quote
echo "Random Quote: $random_quote"

#Save this script in a file, for example, random_quote.sh. Make the script executable with the following command:

chmod +x random_quote.sh

#Now, you can run the script:
./random_quote.sh
