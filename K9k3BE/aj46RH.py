def recursive_sum(nested_list):
    total = 0
    for element in nested_list:
        if isinstance(element, list):
            total += recursive_sum(element)
        else:
            total += element
    return total

#Example
my_nested_list = [1, [2, 3], [4, [5, 6]]]
result = recursive_sum(my_nested_list)
print(result)  # Output will be 21 (1 + 2 + 3 + 4 + 5 + 6)
