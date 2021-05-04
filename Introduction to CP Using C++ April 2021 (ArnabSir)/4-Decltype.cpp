// C++ program to demonstrate use of decltype
#include <iostream>
using namespace std;

int function1() { return 10; }
char function2() { return 'g'; }

int main() {
    // Datatype of x is same as return type of function1()
    decltype(function1()) x;
    decltype(function2()) y;

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;

    int z = 5;
    decltype(z) n = z + 100;
    cout << "z = " << z << " and n = " << n << endl;
    cout << "End of the program..." << endl;
    return 0;
}