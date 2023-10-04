use std::io;

fn main() {
    println!("Geometric Series Sum Calculator");

    // Read the first term (a), common ratio (r), and the number of terms (n)
    let a = read_f64("Enter the first term (a):");
    let r = read_f64("Enter the common ratio (r):");
    let n = read_u32("Enter the number of terms (n):");

    // Calculate the sum of the geometric series
    let sum = geometric_series_sum(a, r, n);

    // Print the result
    println!("The sum of the geometric series is: {}", sum);
}

// Function to calculate the sum of a geometric series
fn geometric_series_sum(a: f64, r: f64, n: u32) -> f64 {
    if r == 1.0 {
        // If the common ratio is 1, the series is simply n times the first term
        a * f64::from(n)
    } else {
        // Calculate the sum using the formula: a * (1 - r^n) / (1 - r)
        a * (1.0 - r.powi(n as i32 + 1)) / (1.0 - r)
    }
}

// Function to read a f64 value from the user
fn read_f64(prompt: &str) -> f64 {
    loop {
        println!("{}", prompt);
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        match input.trim().parse() {
            Ok(value) => return value,
            Err(_) => println!("Invalid input. Please enter a valid number."),
        }
    }
}

// Function to read a u32 value from the user
fn read_u32(prompt: &str) -> u32 {
    loop {
        println!("{}", prompt);
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        match input.trim().parse() {
            Ok(value) => return value,
            Err(_) => println!("Invalid input. Please enter a valid positive integer."),
        }
    }
}
