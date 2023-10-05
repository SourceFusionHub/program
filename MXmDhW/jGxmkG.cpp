// c++ program to calculate area of a rectangle

#include <iostream>
using namespace std;
int rectarea() {
    float length, width, area;
    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;
    area = length * width;
    return area;
}
int main() {
    cout<<rectarea()<<endl;
    return 0;
}
