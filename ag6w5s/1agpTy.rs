use std::io;

fn main() {
    println!("Calculate the area of a regular hexagon");
    
    let mut input = String::new();
    println!("Enter the length of one side of the hexagon: ");
    io::stdin().read_line(&mut input).expect("Failed to read line");
    
    let s: f64 = input.trim().parse().expect("Invalid input. Please enter a number.");
    
    let area = (3.0 * 3.0_f64.sqrt() * s * s) / 2.0;
    
    println!("The area of the regular hexagon with side length {} is {:.2}", s, area);
}
