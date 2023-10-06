# Define a function to evaluate a mathematical expression
def evaluate_expression(expression)
  # Step 1: Tokenize the expression by splitting on operators (+, -, *, /)
  tokens = expression.split(/([+\-*/])/).map(&:strip)
  
  # Initialize a stack to store values and operators
  stack = []
  
  # Step 2: Iterate through tokens
  tokens.each do |token|
    if token.match?(/\d+(\.\d+)?/) # Check if token is a number (including decimals)
      stack.push(token.to_f) # Push numbers onto the stack as floats
    elsif "+-*/".include?(token) # Check if token is an operator
      if stack.length < 2
        raise "Invalid expression: Not enough operands for operator #{token}"
      end
      operand2 = stack.pop
      operand1 = stack.pop
      
      case token
      when "+"
        stack.push(operand1 + operand2)
      when "-"
        stack.push(operand1 - operand2)
      when "*"
        stack.push(operand1 * operand2)
      when "/"
        if operand2 == 0
          raise "Invalid expression: Division by zero"
        end
        stack.push(operand1 / operand2)
      else
        raise "Invalid operator: #{token}"
      end
    else
      raise "Invalid token: #{token}"
    end
  end
  
  # The result should be the only element remaining in the stack
  if stack.length == 1
    return stack.first
  else
    raise "Invalid expression: More than one value remaining in the stack"
  end
end

# Example usage:
expression = "2 + 3 * 4"
begin
  result = evaluate_expression(expression)
  puts "Result: #{result}" # Output: Result: 14.0
rescue StandardError => e
  puts e.message
end
