// C++ code witth conditionals
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Please enter an integer: ";
    cin >> n;
    if (n != 0) {
        cout << "The input number " << n << " is non-zero number..." << endl;
        if (n % 2 == 0) {
            cout << n << " is an EVEN number..." << endl;
        } else {
            cout << n << " is an ODD number..." << endl;
        }
    } else {
        cout << "Input number " << n << " is ZERO..." << endl;
        cout << "So it is neither EVEN nor ODD number..." << endl;
    }

    cout << "End of the program..." << endl;
    return 0;
}