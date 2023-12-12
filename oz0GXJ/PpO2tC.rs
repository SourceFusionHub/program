use std::fs;
use std::io::Write;
use std::path::Path;

fn main() {
    let file_path = Path::new("file.txt");
    let file_version_path = Path::new("file_version.txt");

    // Create a new file and write to it
    let mut file = fs::File::create(&file_path).expect("create failed");
    file.write_all(b"Hello, world!").expect("write failed");

    // Create a new version of the file if it has been modified
    if file_path.exists() && file_version_path.exists() {
        let original = fs::read_to_string(&file_path).expect("read failed");
        let version = fs::read_to_string(&file_version_path).expect("read failed");

        if original != version {
            fs::write(&file_version_path, original).expect("write failed");
            println!("A new version of the file has been created.");
        }
    } else if file_path.exists() {
        fs::copy(&file_path, &file_version_path).expect("copy failed");
        println!("A new version of the file has been created.");
    }
}
