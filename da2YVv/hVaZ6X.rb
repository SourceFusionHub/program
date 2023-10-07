
def gcd(a, b)
  while b != 0
    a, b = b, a % b
  end
  return a
end


def lcm(a, b)
  return (a * b) / gcd(a, b)
end

# Example usage
num1 = 12
num2 = 18
result = lcm(num1, num2)

puts "The LCM of #{num1} and #{num2} is #{result}"
