def max_subarray_with_removal(arr):
    n = len(arr)
    
    # Initialize variables to keep track of the maximum sum subarrays
    max_ending_here = [0] * n
    max_starting_here = [0] * n
    
    # Calculate the maximum sum subarray ending at each index
    max_ending_here[0] = max_starting_here[0] = arr[0]
    max_sum = arr[0]
    
    for i in range(1, n):
        max_ending_here[i] = max(arr[i], max_ending_here[i-1] + arr[i])
        max_starting_here[i] = max(arr[i], max_starting_here[i-1] + arr[i])
        
        max_sum = max(max_sum, max_ending_here[i])
    
    # Calculate the maximum sum subarray starting from each index
    max_sum_with_removal = max_sum
    
    for i in range(1, n-1):
        max_sum_with_removal = max(max_sum_with_removal, max_ending_here[i-1] + max_starting_here[i+1])
    
    return max_sum_with_removal
