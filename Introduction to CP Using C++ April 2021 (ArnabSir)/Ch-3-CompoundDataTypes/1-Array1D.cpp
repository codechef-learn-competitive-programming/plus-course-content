// arrays example
#include <iostream>
using namespace std;

int a [] = {16, 2, 77, 40, 55};
int n, result = 0;

int main () {
    for ( n = 0 ; n < 5 ; ++n ) {
        cout << "Adding " << a[n] << " found at index " << n << endl; 
        result += a[n];
    }
    cout << "So the total  = " << result << endl;
    return 0;
}