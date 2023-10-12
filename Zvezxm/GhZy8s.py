def split_string_into_words(input_string):
    """
    Split a string into a list of words.

    Args:
        input_string (str): The input string to be split.

    Returns:
        list: A list of words extracted from the input string.
    """
    # Use the split() method to split the string into words
    words = input_string.split()
    return words

# Example usage:
if __name__ == "__main__":
    input_string = "This is a sample sentence."
    word_list = split_string_into_words(input_string)
    print(word_list)
