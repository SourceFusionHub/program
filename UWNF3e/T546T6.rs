use std::io;

fn count_occurrences(input_string: &str, character: char) -> usize {
    input_string.chars().filter(|&c| c == character).count()
}

fn main() {
    // Read the input word from the user
    let mut input_word = String::new();
    println!("Enter a word:");
    io::stdin().read_line(&mut input_word).expect("Failed to read line");
    
    // Remove leading and trailing whitespace and convert to lowercase
    let input_word = input_word.trim().to_lowercase();

    // Read the character to count from the user
    println!("Enter a character to count:");
    let mut char_input = String::new();
    io::stdin().read_line(&mut char_input).expect("Failed to read line");

    // Take the first character as the letter to count
    let char_to_count = char_input.chars().next().expect("No character entered");

    let result = count_occurrences(&input_word, char_to_count);
    println!("The character '{}' appears {} times in the word '{}'.", char_to_count, result, input_word);
}
