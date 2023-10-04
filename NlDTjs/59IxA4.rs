fn find_largest_recursive(arr: &[i32], index: usize) -> i32 {
    if index == 0 {
        return arr[0];
    }

    let largest_in_rest = find_largest_recursive(arr, index - 1);
    if arr[index] > largest_in_rest {
        return arr[index];
    } else {
        return largest_in_rest;
    }
}

fn main() {
    let arr = [12, 45, 7, 23, 56, 89, 34, 67];
    let largest = find_largest_recursive(&arr, arr.len() - 1);
    println!("The largest element in the array is: {}", largest);
}
