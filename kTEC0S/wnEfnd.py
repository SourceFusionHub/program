def remove_duplicates(input_list):
    # Use a set to store unique elements
    unique_elements = set()
    # Create a new list with unique elements
    result_list = []
    
    for item in input_list:
        if item not in unique_elements:
            unique_elements.add(item)
            result_list.append(item)
    
    return result_list

# Example usage:
my_list = [1, 2, 2, 3, 4, 4, 5]
result = remove_duplicates(my_list)
print(result)  # Output: [1, 2, 3, 4, 5]
