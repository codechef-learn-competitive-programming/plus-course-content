#include <iostream>
using namespace std;

const double pi = 3.14159;
#define PI 3.14159          // symbolic constant
const char newline = '\n';

int main() {
    int var1 = 10;
    int var2(20);
    int var3{30};
    cout << "var1 = " << var1 << ", var2 = " << var2 << " and var3 = " << var3 << endl;

    double r = 15.0;
    double circle1, circle2;
    circle1 = 2 * pi * r;
    circle2 = 2 * PI * r;
    cout << "circle1 = " << circle1 << " and circle2 = " << circle2 << newline; 

    bool var_bool = true;
    cout << "var_bool = " << var_bool << " with sizeof = " << sizeof(var_bool) << endl;
    int var_int = 100;
    cout << "var_int = " << var_int << " with sizeof = " << sizeof(var_int) << endl;
    cout << "datatype of var_int = " << typeid(var_int).name() << endl;
    short int var_sint = 100;
    cout << "var_sint = " << var_sint << " with sizeof = " << sizeof(var_sint) << endl;

    cout << "Displaying sizeof() of multiple datatypes..." << endl;
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of short int: " << sizeof(short int) << endl;
    cout << "size of char: " << sizeof(char) << endl;
    cout << "size of float: " << sizeof(float) << endl;
    cout << "size of long int: " << sizeof(long int) << endl;
    cout << "size of long long int: " << sizeof(long long int) << endl;
    cout << "size of wchar_t: " << sizeof(wchar_t) << endl;
    cout << "size of double: " << sizeof(double) << endl;
    cout << "size of long double: " << sizeof(long double) << endl;

    int var4 = 100; 
    cout << "var4 = " << var4 << endl;
    var4 = 0100; // = 1 x 8^2 + 0 x 8^1 + 0 x 8^0 = 64
    cout << "var4 = " << var4 << endl;
    var4 = 0x100; 
    cout << "var4 = " << var4 << endl;

    cout << "End of the program..." << endl;
    return 0;
}