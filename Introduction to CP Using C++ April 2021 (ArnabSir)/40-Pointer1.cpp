#include <iostream>
using namespace std;
void function_cv(int, int);
void function_ca(int *, int *);
void function_cr(int &, int &);
int main() {
    int a = 100, b = 200;

    cout << endl << "Before function_cv() a = " << a << " and b = " << b << endl;
    function_cv(a, b);
    cout << "After function_cv() a = " << a << " and b = " << b << endl;

    cout << endl << "Before function_ca() a = " << a << " and b = " << b << endl;
    function_ca(&a, &b);
    cout << "After function_ca() a = " << a << " and b = " << b << endl;

    a = 100; b = 200;
    cout << endl << "Before function_cr() a = " << a << " and b = " << b << endl;
    function_cr(a, b);
    cout << "After function_cr() a = " << a << " and b = " << b << endl;

    cout << "End of the program..." << endl;

    return 0;
}

void function_cv(int aa, int bb) {   // call by value
    cout << "In function function_cv() aa = " << aa << " and bb = " << bb << endl;
    aa = 111; bb = 222;
    cout << "In function function_cv() aa = " << aa << " and bb = " << bb << endl;
}

void function_ca(int *aa, int *bb) {  // passing addresses as a value
    cout << "In function function_ca() *aa = " << *aa << " and *bb = " << *bb << endl;
    *aa = 111; *bb = 222;
    cout << "In function function_ca() *aa = " << *aa << " and *bb = " << *bb << endl;
}

void function_cr(int &aa, int &bb) {   // call by refeence
    cout << "In function function_cr() aa = " << aa << " and bb = " << bb << endl;
    aa = 111; bb = 222;
    cout << "In function function_cr() aa = " << aa << " and bb = " << bb << endl;
}