def third_largest(arr)
  if arr.length < 3
    return "Array does not have at least three elements."
  end

  
  sorted_arr = arr.uniq.sort.reverse

  
  return sorted_arr[2]
end

#Example
arr = [5, 2, 8, 7, 1, 9]
result = third_largest(arr)
puts "Third largest number in the array is: #{result}"
