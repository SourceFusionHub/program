def longestSubarrayWithSumAtMostK(nums, k):
  if not nums:
    return []

  res = [min(nums)] if min(nums) <= k else []
  curr_sum = 0
  l, r = 0,-1
  while r < len(nums)-1:
    r += 1
    curr_sum += nums[r]

    while curr_sum > k and l <= r:
      curr_sum -= nums[l]
      l += 1

    if r - l + 1 > len(res):
      res = nums[l:r+1]

  return res

nums = [1, 2, 3, 4, 5]
k = 8
result = longestSubarrayWithSumAtMostK(nums, k)
print(result)  # Output: [1, 2, 3]
