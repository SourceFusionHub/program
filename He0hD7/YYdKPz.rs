// Import the image crate
use image::{GenericImageView, ImageOutputFormat};

// Define the main function
fn main() {
    // Get the command line arguments
    let args: Vec<String> = std::env::args().collect();

    // Check if there are enough arguments
    if args.len() < 3 {
        println!("Usage: {} input_file output_file", args[0]);
        return;
    }

    // Get the input and output file names
    let input_file = &args[1];
    let output_file = &args[2];

    // Open the input image file
    let img = match image::open(input_file) {
        Ok(img) => img,
        Err(e) => {
            println!("Error opening {}: {}", input_file, e);
            return;
        }
    };

    // Convert the image to grayscale
    let gray_img = img.grayscale();

    // Rotate the image by 90 degrees clockwise
    let rotated_img = gray_img.rotate90();

    // Save the image to the output file
    match rotated_img.save_with_format(output_file, ImageOutputFormat::Png) {
        Ok(_) => println!("Image saved to {}", output_file),
        Err(e) => println!("Error saving to {}: {}", output_file, e),
    }
}
