use std::io;

fn main() {
    // Prompt the user for input
    println!("Enter the base of the triangle:");
    let mut base = String::new();
    io::stdin().read_line(&mut base).expect("Failed to read line");

    println!("Enter the height of the triangle:");
    let mut height = String::new();
    io::stdin().read_line(&mut height).expect("Failed to read line");

    // Parse input strings to f64 (floating-point number)
    let base: f64 = match base.trim().parse() {
        Ok(num) => num,
        Err(_) => {
            println!("Error: Please enter a valid number for the base.");
            return;
        }
    };

    let height: f64 = match height.trim().parse() {
        Ok(num) => num,
        Err(_) => {
            println!("Error: Please enter a valid number for the height.");
            return;
        }
    };

    // Calculate the area of the triangle
    let area = 0.5 * base * height;

    // Display the result
    println!("The area of the triangle is: {}", area);
}
