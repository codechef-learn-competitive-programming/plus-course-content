#include <iostream>
using namespace std;
int main() {
    int num1, num2, num3, max1, max2;
    cout << "Please enter the first number: ";
    cin >> num1;
    cout << "Please enter the second number: ";
    cin >> num2;
    cout << "Please enter the third number: ";
    cin >> num3;
    if (num1 > num2) {
        max1 = num1;
        max2 = num2;
    } else {
        max1 = num2;
        max2 = num1;
    }

    if (num3 > max1) {
        cout << "So the second maximum is " << max1 << endl;
    } else if (num3 > max2) {
        cout << "So the second maximum is " << num3 << endl;
    } else {
        cout << "So the second maximum is " << max2 << endl;
    }

    cout << "End of the program..." << endl;
    return 0;
}