use std::io;
fn main() {
    println!("Calculate the area of an ellipse.");
    let major_axis:f64=get_user_input("Enter the length of the major axis:");
    let minor_axis:f64=get_user_input("Enter the length of the minor axis:");
    let pi: f64=std::f64::consts::PI;
    let area: f64 = pi * major_axis * minor_axis;
    println!("The area of the ellipse is: {}", area);
}
fn get_user_input(prompt: &str) -> f64 {
    loop {
        println!("{}", prompt);
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read line");
        match input.trim().parse() {
            Ok(value) => return value,
            Err(_) => println!("Invalid input. Please enter a valid number."),
        }
    }
}
