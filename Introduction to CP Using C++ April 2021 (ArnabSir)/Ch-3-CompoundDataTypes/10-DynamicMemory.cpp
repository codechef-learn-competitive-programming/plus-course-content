#include <iostream>
#include <new>
using namespace std;

int main () {
    int i, n;
    int * p;
    cout << "How many numbers would you like to enter? ";
    cin >> i;
    p = new (nothrow) int[i];
    // The other method is known as nothrow, and what happens when it is used is that when 
    // a memory allocation fails, instead of throwing a bad_alloc exception or terminating 
    // the program, the pointer returned by new is a null pointer, and the program continues 
    // its execution normally.

    if (p == nullptr)
        cout << "Error: memory could not be allocated" << endl;
    else {
        for (n = 0; n < i; n++) {
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: " << endl;
        for (n = 0; n < i; n++)
            cout << p[n] << ", ";
        delete[] p;
    }
    cout << endl << "End of the program..." << endl;
    return 0;
}