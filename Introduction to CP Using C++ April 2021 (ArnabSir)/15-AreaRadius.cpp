#include <iostream>
using namespace std;
#define pi 3.14159
int main() {
    int r;
    double area, perimeter;

    cout << "Please enter the radius of the circle: ";
    cin >> r;

    area = pi * r * r;
    perimeter = 2 * pi * r;

    cout << "Radius = " << r << endl;
    cout << "Area = " << area << endl; 
    cout << "Perimeter = " << perimeter << endl;

    return 0;
}