import re

def is_valid_ipv4(ip):
    # Define a regular expression pattern for a valid IPv4 address
    ipv4_pattern = r'^(\d{1,3}\.){3}\d{1,3}$'

    # Check if the input string matches the pattern
    if re.match(ipv4_pattern, ip):
        # Split the string into octets
        octets = ip.split('.')
        
        # Check if each octet is in the valid range (0-255)
        for octet in octets:
            if 0 <= int(octet) <= 255:
                continue
            else:
                return False
        return True
    else:
        return False

# Test cases
print(is_valid_ipv4("192.168.0.1"))  # True
print(is_valid_ipv4("256.0.0.1"))    # False (octet > 255)
print(is_valid_ipv4("10.0.0.256"))   # False (octet > 255)
print(is_valid_ipv4("192.168.0"))    # False (not enough octets)
print(is_valid_ipv4("abc.def.ghi.jkl"))  # False (invalid characters)
