fn main() {
    let numbers = [10, 5, 7, 3, 8, 12, 1];

    println!("The largest element is: {}", find_largest(&numbers));
}

// Function to find the largest element in an array
fn find_largest(arr: &[i32]) -> i32 {
    let mut largest = arr[0];

    for &num in arr {
        if num > largest {
            largest = num;
        }
    }

    largest
}