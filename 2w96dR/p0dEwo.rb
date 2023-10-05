print "Enter a number: "
number = gets.to_f  
# Calculate the square root
if number >= 0
  square_root = Math.sqrt(number)
  puts "The square root of #{number} is #{square_root}"
else
  puts "Cannot calculate the square root of a negative number"
end
