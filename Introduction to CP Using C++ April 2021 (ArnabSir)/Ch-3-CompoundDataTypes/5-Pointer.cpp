#include <iostream>
using namespace std;

int main () {
    int firstvalue, secondvalue;
    int * mypointer;

    mypointer = &firstvalue; *mypointer = 10;
    mypointer = &secondvalue; *mypointer = 20;
    cout << "firstvalue is " << firstvalue << '\n';
    cout << "secondvalue is " << secondvalue << '\n';

    return 0;
}