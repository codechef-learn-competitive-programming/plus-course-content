// Find out all possible 3-digit Triode numbers. Let x be a Triode number then
// x, 2x and 3x will have all distinct digits

#include <iostream>
using namespace std;
int main() {
    int n, x, last_digit, i;
    
    for (n = 102; n <= 498; n++) {
        int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (i = 1; i <= 3; i++) {
            x = i * n;
            while (x != 0) {
                last_digit = x % 10;
                if (a[last_digit] == 0) a[last_digit] = 1;
                else break;
                x = x / 10;
            }
            if (x != 0) break;
        }
        // if (x == 0) cout << "Triode number: " << n << ", " << 2*n << ", " << 3*n << endl;
        if (i > 3) cout << "Triode number: " << n << ", " << 2*n << ", " << 3*n << endl;
    }
    cout << endl << "End of the program..." << endl;
    return 0;
}