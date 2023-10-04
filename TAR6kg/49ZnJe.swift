func maxSubarraySum(_ nums: [Int]) -> Int {
    guard !nums.isEmpty else {
        // Handle the case of an empty array.
        return 0
    }
    
    var maxEndingHere = nums[0]
    var maxSoFar = nums[0]
    
    for i in 1..<nums.count {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i])
        maxSoFar = max(maxSoFar, maxEndingHere)
    }
    
    return maxSoFar
}
