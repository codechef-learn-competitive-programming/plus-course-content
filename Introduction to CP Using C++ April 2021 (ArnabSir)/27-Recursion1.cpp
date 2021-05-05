#include <iostream>
using namespace std;
int main() {
    int factorial_nr(int);     // function prototype declaration
    int factorial_r(int);      // function prototype declaration
    int n, fact;
    cout << endl << "Please enter an integer: ";
    cin >> n;
    fact = factorial_nr(n);
    cout << endl << "So the factorial of " << n << " is " << fact << "...";
    fact = factorial_r(n);
    cout << endl << "So the factorial of " << n << " is " << fact << "...";
    cout << endl << "End of the program..." << endl;
}

int factorial_r(int num) {
    if (num == 0 || num == 1)            // base case
        return 1;
    int f = num * factorial_r(num - 1);
    return f;
    // return num * factorial_r(num - 1);   // recursive case (direct)
}

int factorial_nr(int num) {
    int f = 1;
    for (int i = 1; i <= num; i++) {
        f *= i;
    }
    return f;
}