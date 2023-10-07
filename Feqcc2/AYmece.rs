use std::io;

fn main() {
    println!("Reverse Order of Words in a Sentence");

    // Read the input sentence from the user
    let input_sentence = read_input("Enter a sentence:");

    // Split the sentence into words and collect them into a vector
    let words: Vec<&str> = input_sentence.split_whitespace().collect();

    // Reverse the order of words
    let reversed_sentence = reverse_words(&words);

    // Print the reversed sentence
    println!("Reversed Sentence: {}", reversed_sentence);
}

// Function to reverse the order of words
fn reverse_words(words: &[&str]) -> String {
    let mut reversed_words: Vec<&str> = words.iter().rev().map(|&w| w).collect();
    reversed_words.join(" ")
}

// Function to read a line of input from the user
fn read_input(prompt: &str) -> String {
    println!("{}", prompt);
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    input.trim().to_string()
}
