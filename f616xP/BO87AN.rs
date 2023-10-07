use std::io::Write;

fn read_string() -> String
{
  let mut text = String::new();
  std::io::stdin().read_line(&mut text)
    .expect("Error while getting input");
  return text;
}

fn exit()
{
  println!("Press enter to exit...");
  read_string();
}

fn main()
{
  println!("\n");
  let mut dec: u64 = 0;
  print!("Enter a binary number: "); 
  std::io::stdout().flush().unwrap();
  let bin = read_string();
  for (i, bit) in bin.trim().chars().rev().enumerate()
  {
    let bit_num = bit.to_digit(10)
      .expect("Error while parsing bit");
    dec += (bit_num * u32::pow(2, i as u32)) as u64;
  }
  println!("Binary: {}, Decimal: {}", bin.trim(), dec);
  exit();
}
