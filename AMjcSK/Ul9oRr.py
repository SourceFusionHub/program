def LongestSubarrayWithSumDivisibleByK(nums, k):

    prefix_sum = 0
    remainder_index_map = {}
    max_length = 0

    for i, num in enumerate(nums):
        prefix_sum += num
        remainder = prefix_sum % k

        if remainder < 0:
            remainder += k

        if remainder == 0:
            max_length = i + 1
        elif remainder in remainder_index_map:
            max_length = max(max_length, i - remainder_index_map[remainder])

        if remainder not in remainder_index_map:
            remainder_index_map[remainder] = i

    return max_length

nums = list(map(int, input("Enter a list of integers separated by spaces: ").split()))

k = int(input("Enter the value of k: "))

result = LongestSubarrayWithSumDivisibleByK(nums, k)
print("The longest subarray with sum divisible by K is of length:", result)
