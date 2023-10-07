def convert_to_uppercase(input_list):
    uppercase_list = []
    for string in input_list:
        uppercase_list.append(string.upper())
    return uppercase_list


def convert_to_uppercase(input_list):
    return [string.upper() for string in input_list]


input_list = ["apple", "banana", "cherry"]
result = convert_to_uppercase(input_list)
print(result)
