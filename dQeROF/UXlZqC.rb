arr = [1, 2, 3, 4, 5]

element_to_find = 3

index = arr.index(element_to_find)

if index
  puts "The index of #{element_to_find} is #{index}."
else
  puts "#{element_to_find} not found in the array."
end
