def int_to_roman(num)
  # Define the Roman numeral symbols and their corresponding values
  roman_numerals = {
    'M' => 1000,
    'CM' => 900,
    'D' => 500,
    'CD' => 400,
    'C' => 100,
    'XC' => 90,
    'L' => 50,
    'XL' => 40,
    'X' => 10,
    'IX' => 9,
    'V' => 5,
    'IV' => 4,
    'I' => 1
  }

  roman_result = ''

  # Iterate through the Roman numerals and build the result
  roman_numerals.each do |symbol, value|
    while num >= value
      roman_result += symbol
      num -= value
    end
  end

  return roman_result
end

# Get user input for the number
print "Enter a number: "
number = gets.chomp.to_i

# Check if the input is valid
if number >= 1 && number <= 3999
  roman_numeral = int_to_roman(number)
  puts "Roman numeral representation: #{roman_numeral}"
else
  puts "Invalid input. Please enter a number between 1 and 3999."
end
