fn find_median(mut nums: Vec<i32>) -> f64 {
    nums.sort_unstable();  // Sort the numbers

    let mid = nums.len() / 2;  // Find the middle index
    if nums.len() % 2 == 0 {
        (nums[mid - 1] + nums[mid]) as f64 / 2.0
    } else {
        nums[mid] as f64
    }
}

fn main() {
    let numbers = vec![5, 2, 9, 3, 7, 6];
    println!("Median: {}", find_median(numbers));
}

