using System;

int sumEven() {
    int sum = 0;
    for (int i = 2; i <= 100; i += 2) {
        sum += i;
    }
    return sum;
}
void Main() {
    int result = sumEven();
    Console.WriteLine("The sum of all even numbers from 1 to 100 is " + result);
}
