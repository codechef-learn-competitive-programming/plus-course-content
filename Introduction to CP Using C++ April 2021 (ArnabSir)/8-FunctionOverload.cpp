// Overloaded functions may have the same definition.
#include <iostream>
using namespace std;

int operate (int a, int b) {
    return (a * b);
}

double operate (double a, double b) {
    return (a / b);
}

int main () {
    int x = 5, y = 2;
    double n = 5.0, m = 2.0;
    cout << operate (x, y) << '\n';
    cout << operate (n, m) << '\n';
    return 0;
}