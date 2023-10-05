#include <iostream>
using namespace std;

int main()
{
  double celsius, fahrenheit;

  // Prompt the user to enter the temperature in Celsius
  cout << "Enter the temperature in Celsius: ";
  cin >> celsius;

  // Convert Celsius to Fahrenheit using the formula
  fahrenheit = (celsius * 9 / 5) + 32;

  // Display the result
  cout << "Temperature in Fahrenheit: " << fahrenheit << "°F" << endl;

  return 0;
}
