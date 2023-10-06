struct Ellipse {
    major_axis: f64,
    minor_axis: f64,
}

impl Ellipse {
    // Constructor for creating a new Ellipse
    fn new(major_axis: f64, minor_axis: f64) -> Self {
        Ellipse {
            major_axis,
            minor_axis,
        }
    }

    // Method to calculate the area of the ellipse
    fn area(&self) -> f64 {
        std::f64::consts::PI * self.major_axis * self.minor_axis
    }
}

fn main() {
    // Create an ellipse with major and minor axes
    let ellipse = Ellipse::new(5.0, 3.0);

    // Calculate the area of the ellipse
    let area = ellipse.area();

    println!("The area of the ellipse is: {:.2}", area);
}
