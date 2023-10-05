fn longest_common_substring(str1: &str, str2: &str) -> String {
    let len1 = str1.len();
    let len2 = str2.len();
    
    // Create a 2D table to store the lengths of common substrings
    let mut dp = vec![vec![0; len2 + 1]; len1 + 1];
    let mut max_len = 0; // Length of the longest common substring
    let mut end_index = 0; // Ending index of the longest common substring in str1
    
    for i in 1..=len1 {
        for j in 1..=len2 {
            if str1.chars().nth(i - 1) == str2.chars().nth(j - 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if dp[i][j] > max_len {
                    max_len = dp[i][j];
                    end_index = i;
                }
            }
        }
    }
    
    if max_len == 0 {
        return String::new(); // No common substring found
    }
    
    let start_index = end_index - max_len;
    let common_substring: String = str1.chars().skip(start_index).take(max_len).collect();
    
    common_substring
}

fn main() {
    let str1 = "abcdefg";
    let str2 = "bcdfgh";
    
    let result = longest_common_substring(str1, str2);
    
    println!("Longest Common Substring: {}", result);
}
