#include <iostream>
using namespace std;

int main() {
    double length, width, height;

    cout << "Enter the length: ";
    cin >> length;

    cout << "Enter the width: ";
    cin >> width;

    cout << "Enter the height: ";
    cin >> height;

    double volume = length * width * height;

    cout << "The volume of the rectangular prism is: " << volume << endl;

    return 0;
}
