def is_alpha?(string)
  !string.match(/[^A-Za-z]/)
end
print "Enter string: ";
str = gets.chomp;  
puts is_alpha?(str)
