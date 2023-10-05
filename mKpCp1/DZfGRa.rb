def is_palindrome?(str)
  str = str.downcase.gsub(/\s+/, '')
  str == str.reverse
end

print "Enter a string: "
user_input = gets.chomp

if is_palindrome?(user_input)
  puts "#{user_input} is a palindrome."
else
  puts "#{user_input} is not a palindrome."
end
