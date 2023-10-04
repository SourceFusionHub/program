def sum_of_squares(n)
  sum = 0
  (1..n).each do |num|
    sum += num**2
  end
  return sum
end

# Example usage:
n = 5
result = sum_of_squares(n)
puts "The sum of squares from 1 to #{n} is #{result}"
