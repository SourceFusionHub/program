# Sample array
array = [10, 20, 30, 40, 50, 30]

# Element to search for
element_to_find = 30

# Find the index of the first occurrence of the element
index = array.index(element_to_find)

if index
  puts "The first occurrence of #{element_to_find} is at index #{index}."
else
  puts "#{element_to_find} was not found in the array."
end
