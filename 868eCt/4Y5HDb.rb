def is_valid_hex_color?(color_code)
    hex_color_pattern = /^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$/
    return color_code =~ hex_color_pattern
  end
  
  puts "Enter a hexadecimal color code (e.g., #RRGGBB or #RGB):"
  user_input = gets
  
  if is_valid_hex_color?(user_input.strip)
    puts "#{user_input} is a valid hexadecimal color code."
  else
    puts "#{user_input} is not a valid hexadecimal color code."
  end