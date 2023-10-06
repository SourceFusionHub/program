#include <iostream>
using namespace std;

double sum_of_series(int n) {
  double sum = 0.0;
  for (int i = 1; i <= n; i++) {
    sum += 1.0 / i;
  }
  return sum;
}

int main() {
  int n;
  cout << "Enter the number of terms: ";
  cin >> n;

  double sum = sum_of_series(n);
  cout << "The sum of the series is: " << sum << endl;

  return 0;
}
