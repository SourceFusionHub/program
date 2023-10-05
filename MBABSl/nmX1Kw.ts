function binarySearch(nums: number[], target: number): number {
  let left: number = 0;
  let right: number = nums.length - 1;

  while (left <= right) {
    const mid: number = Math.floor((left + right) / 2);

    if (nums[mid] === target) return mid;
    if (target < nums[mid]) right = mid - 1;
    else left = mid + 1;
  }

  return -1; // Return -1 if target is not found
}

//Time Complexity:
//Worst case: O(log n)
//Average case: O(log n)
//Best case: O(1)
