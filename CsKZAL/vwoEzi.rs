use std::f64::consts::PI;

// Defining a structure to represent a sector of an ellipse
struct Sector {
    semi_major_axis: f64,
    semi_minor_axis: f64,
    central_angle: f64, // Angle in radians
}

impl Sector {
    // Method to calculate the area of the sector
    fn calculate_area(&self) -> f64 {
        0.5 * self.semi_major_axis * self.semi_minor_axis * self.central_angle.sin()
    }
}

fn main() {
    // Input: Asking the user to enter the semi-major axis, semi-minor axis, and central angle
    println!("Enter the semi-major axis of the ellipse:");
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Failed to read line");
    let semi_major_axis: f64 = input.trim().parse().expect("Invalid input");

    println!("Enter the semi-minor axis of the ellipse:");
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Failed to read line");
    let semi_minor_axis: f64 = input.trim().parse().expect("Invalid input");

    println!("Enter the central angle (in degrees):");
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Failed to read line");
    let central_angle_degrees: f64 = input.trim().parse().expect("Invalid input");

    // Converting the central angle to radians
    let central_angle = central_angle_degrees.to_radians();

    // Creating a Sector instance
    let sector = Sector {
        semi_major_axis,
        semi_minor_axis,
        central_angle,
    };

    // Calculating and displaying the area of the sector
    let area = sector.calculate_area();
    println!("The area of the sector of the ellipse is: {}", area);
}
