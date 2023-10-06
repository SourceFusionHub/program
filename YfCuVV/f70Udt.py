# Python program to create a function to find the longest word in a string.

def longest_words(input_string):
    words = input_string.split()
    
    longest_words = []
    max_length = 0
    
    for word in words:
        cleaned_word = "".join(e for e in word if e.isalnum())

        word_length = len(cleaned_word)
        
        if word_length > max_length:
            longest_words = [cleaned_word]
            max_length = word_length
        elif word_length == max_length:
            longest_words.append(cleaned_word)

    return longest_words

input_string = input("Enter a string: ")
longest_words_list = longest_words(input_string)

if longest_words_list:
    print("Longest words:", longest_words_list)
else:
    print("No words found in the input string.")



## Another solution using regular expressions

# import re

# def longest_words(input_string):
#     words = re.findall(r'\b\w+\b', input_string)

#     if not words:
#         return []

#     max_length = max(len(word) for word in words) 
#     longest_words = [word for word in words if len(word) == max_length]  

#     return longest_words

# input_string = input("Enter a string: ")
# longest_words_list = longest_words(input_string)

# if longest_words_list:
#     print("Longest words:", longest_words_list)
# else:
#     print("No words found in the input string.")
