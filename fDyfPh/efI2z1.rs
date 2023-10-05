fn calculate_sector_area(radius: f64, central_angle: f64) -> f64 {
    const PI: f64 = std::f64::consts::PI;
    let sector_area = 0.5 * radius * radius * central_angle;
    sector_area
}

fn main() {
    let radius = 5.0; // Replace this with the desired radius of the circle
    let central_angle = 1.2; // Replace this with the desired central angle in radians

    let sector_area = calculate_sector_area(radius, central_angle);
    println!("Area of the sector: {:.2}", sector_area);
}
