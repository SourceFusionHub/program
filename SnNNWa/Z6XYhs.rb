def gcd(a, b)
    while b != 0
      a, b = b, a % b
    end
    return a
  end
  
  # Input two numbers from the user
  print "Enter the first number: "
  num1 = gets.chomp.to_i
  print "Enter the second number: "
  num2 = gets.chomp.to_i
  
  # Calculate and display the GCD
  result = gcd(num1, num2)
  puts "The GCD of #{num1} and #{num2} is #{result}"
  