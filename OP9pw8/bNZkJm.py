def insert_at_position(lst, position, element):
    if position < 0:
        print("Position cannot be negative")
        return lst
    elif position > len(lst):
        print("Position out of range, appending element to the end of the list")
        lst.append(element)
    else:
        lst.insert(position, element)
    
    return lst

# Test
lst = [1, 2, 3, 4, 5]
inserted_lst = insert_at_position(lst, 2, 99)
print(inserted_lst)  
