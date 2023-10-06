def fibonacci(n)
  fib_sequence = []
  if n >= 1
    fib_sequence << 0
  end
  if n >= 2
    fib_sequence << 1
  end

  while fib_sequence.length < n
    next_term = fib_sequence[-1] + fib_sequence[-2]
    fib_sequence << next_term
  end

  return fib_sequence
end

# Input the number of terms you want in the Fibonacci sequence
print "Enter the number of Fibonacci terms to generate: "
n = gets.chomp.to_i

if n <= 0
  puts "\nPlease enter a positive integer greater than 0."
else
  result = fibonacci(n)
  puts "\nThe Fibonacci sequence of #{n} terms is: #{result.join(', ')}"
end
