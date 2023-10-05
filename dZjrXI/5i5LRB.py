import re

def validEmail(email):
    # Regular expression pattern for a valid email address
    pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    
    # Use the re.match() function to check if the email matches the pattern
    if re.match(pattern, email):
        return True
    else:
        return False

# Example usage:
email = "example@email.com"
print(f"Is {email} a valid email address: {validEmail(email)}")