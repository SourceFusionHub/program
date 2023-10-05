def find_median(numbers):
    sorted_numbers = sorted(numbers)
    
    n = len(sorted_numbers)
    
    if n % 2 == 0:
        middle1 = sorted_numbers[n // 2 - 1]
        middle2 = sorted_numbers[n // 2]
        median = (middle1 + middle2) / 2.0
    else:
        median = sorted_numbers[n // 2]
    
    return median

# Example usage:
numbers = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
median = find_median(numbers)
print("Median:", median)
