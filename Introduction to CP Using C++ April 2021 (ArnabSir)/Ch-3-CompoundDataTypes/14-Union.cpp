// C++ program to illustrate the use of the union
#include <iostream>
using namespace std;
  
// Defining a Union
union myUnion {
    int intVar;
    char charVar;
};
  
// Driver Code
int main() {
    // Intializing Union
    union myUnion mu1;  

    mu1.intVar = 325; // 325 = 256 + 64 + 4 + 1 = 1 0100 0101
    cout << "mu1.intVar = " << mu1.intVar << " and mu1.charVar = " << mu1.charVar << endl;
    mu1.charVar = 'A';
    cout << "mu1.intVar = " << mu1.intVar << " and mu1.charVar = " << mu1.charVar << endl;

    return 0;
}