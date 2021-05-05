#include <iostream>
using namespace std;
int main() {
    int a = 10;
    int b = 10;
    int result1, result2;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    result1 = a++;    // example of post increment
    cout << "result1 = " << result1 << endl;
    result2 = ++b;    // example of pre increment
    cout << "result2 = " << result2 << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "End of the program..." << endl;
}