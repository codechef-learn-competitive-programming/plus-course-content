// function example
#include <iostream>
using namespace std;

int addition (int a = 100, int b = 200) {   // positional parameters and call by value
    int r;
    r = a + b;
    return r;
}

void swap(int &aa, int &bb) {  // call by reference
    cout << "Performing the swapping operation..." << endl;
    int temp = aa;
    aa = bb;
    bb = temp;
}

// const guarantees that reference parameters are not going to be modified by this function
inline string concatenate (const string &m1, const string &m2) {
    return m1 + " " + m2;
}

// recursive function
long factorial_r (long a) {
    if (a > 1)
        return (a * factorial_r (a-1));
    else
        return 1;
}

void end_message () {  // Functions with no type. The use of void
    cout << endl << "End of the program..." << endl;
}

int main () {
    int a = 5, b = 3, c;
    c = addition (a, b);        // positional arguments
    cout << "The result of " << a << " + " << b << " is " << c << endl;
    c = addition (a);           // positional arguments
    cout << "The result of " << a << " + 200 is " << c << endl;
    c = addition ();           // positional arguments
    cout << "The result of 100 + 200 is " << c << endl;
    cout << endl << "Before swapping a = " << a << " and b = " << b << endl;
    swap(a, b);
    cout << "After swapping a = " << a << " and b = " << b << endl;
    string msg1 = "Good", msg2 = "Bye";
    cout << "So the concatenated string is " << concatenate(msg1, msg2) << endl;
    long number = 6;
    cout << number << "! = " << factorial_r (number);
    end_message ();

    return 0;           
    // return EXIT_SUCCESS;
    // 0 - The program was successful
    // EXIT_SUCCESS	- The program was successful (same as above). Defined in header <cstdlib>
    // EXIT_FAILURE	- The program failed. Defined in header <cstdlib>
}