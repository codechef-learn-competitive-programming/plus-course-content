// increaser
#include <iostream>
using namespace std;

void increase (void* data, int psize) {
    if ( psize == sizeof(char) ) {
        char* pchar; pchar = (char *) data; ++(*pchar);
    } else if (psize == sizeof(int) ) { 
        int* pint; pint = (int *) data; ++(*pint);
    }
}

int main () {
    char a = 'x';
    int b = 1602;
    cout << "Before increase - " << a << ", " << b << endl;
    increase (&a, sizeof(a));
    increase (&b, sizeof(b));
    cout << "After increase - " << a << ", " << b << endl;
    return 0;
}