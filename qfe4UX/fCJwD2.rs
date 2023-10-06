use std::io;

fn main() {
    // Prompt the user for the base and height of the parallelogram
    println!("Enter the base of the parallelogram:");
    let mut base = String::new();
    io::stdin().read_line(&mut base).expect("Failed to read line");

    println!("Enter the height of the parallelogram:");
    let mut height = String::new();
    io::stdin().read_line(&mut height).expect("Failed to read line");

    // Parse the input strings to f32 (floating-point) numbers
    let base: f32 = base.trim().parse().expect("Invalid input");
    let height: f32 = height.trim().parse().expect("Invalid input");

    // Calculate the area of the parallelogram
    let area = base * height;

    // Display the result
    println!("The area of the parallelogram is: {}", area);
}
