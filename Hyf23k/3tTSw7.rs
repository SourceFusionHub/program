fn main() {
    let num =-14;
    let value = abs(num);
    
    println!("the absolute value of {} is {}.", num, value);
}
fn abs(x: i32) -> i32 {
    
    if x >=0 {
        return x;
    } else {
       return -x;
    }
}