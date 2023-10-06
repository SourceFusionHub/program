use std::io::{self, Write};

enum Command {
    Increment,
    Decrement,
    Print,
    Halt,
}

fn interpret(program: &str) {
    let mut memory = 0;

    for c in program.chars() {
        let command = match c {
            '+' => Command::Increment,
            '-' => Command::Decrement,
            '*' => Command::Print,
            '!' => Command::Halt,
            _ => continue, 
        };

        match command {
            Command::Increment => memory += 1,
            Command::Decrement => memory -= 1,
            Command::Print => {
                print!("{}", memory as u8 as char);
                io::stdout().flush().unwrap();  
            }
            Command::Halt => break,
        }
    }
}

fn main() {
    println!("Enter the esoteric code (use +, -, *, !):");

    let mut input = String::new();
    io::stdout().flush().unwrap();

    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    interpret(&input);
}
