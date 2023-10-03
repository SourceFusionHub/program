def contains_only_digits(input_str):
    # Check if all characters in the input string are digits
    return input_str.isdigit()

# Example usage:
input_string = "12345"
result = contains_only_digits(input_string)
print(result)  # True

input_string = "12345a"
result = contains_only_digits(input_string)
print(result)  # False
