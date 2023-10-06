fn square(num: f64) -> f64 {
    num * num
}

fn main() {
    let number = 5.0; 
    let result = square(number);
    println!("The square of {} is: {}", number, result);
}
