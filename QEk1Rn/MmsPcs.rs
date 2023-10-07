use std::io;

fn sum_of_digits(num:&mut  i32)->i32{
    let mut num=num.clone();
    let mut sum=0;
    while num!=0{
        sum+=num%10;
        num/=10
    }
    sum

}

fn main() {

    let mut inp=String::new();

    println!("Enter a number");
    io::stdin().read_line(&mut inp).expect("invalid input");

    let mut inp:i32= inp.trim().parse().expect("invalid input");

    let digit_sum=sum_of_digits(&mut inp);

    println!("sum of digits of {inp}  is {digit_sum} ")

}
