def insert_element_at_position(lst, element, position):
    
    if position < 0:
        position = 0
    elif position > len(lst):
        position = len(lst)
    
    lst.insert(position, element)
    return lst

# Example usage:
my_list = [1, 2, 3, 4, 5]
element_to_insert = 100
insert_position = 2

result_list = insert_element_at_position(my_list, element_to_insert, insert_position)
print(result_list)
