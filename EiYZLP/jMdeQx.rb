def is_even(num)
    return num % 2 == 0
end

print "Enter a number: "
n = gets.chomp.to_i

if is_even(n)
    puts "#{n} is even"
else
    puts "#{n} is odd"
end
  