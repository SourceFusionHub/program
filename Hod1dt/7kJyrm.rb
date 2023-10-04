# Define a regex pattern for the specific phone number format
phone_number_pattern = /^\d{3}-\d{3}-\d{4}$/

# Input string to check
input_string = "123-456-7890"

# Check if the input string matches the phone number pattern
if input_string.match?(phone_number_pattern)
  puts "Valid phone number: #{input_string}"
else
  puts "Invalid phone number: #{input_string}"
end
