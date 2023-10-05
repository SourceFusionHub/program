# Function to calculate the perimeter of a rectangle
def rectangle_perimeter(length, width)
  perimeter = 2 * (length + width)
  return perimeter
end

# Input the length and width of the rectangle
print "Enter the length of the rectangle: "
length = gets.chomp.to_f

print "Enter the width of the rectangle: "
width = gets.chomp.to_f

# Calculate and display the perimeter
perimeter = rectangle_perimeter(length, width)
puts "The perimeter of the rectangle is: #{perimeter}"
