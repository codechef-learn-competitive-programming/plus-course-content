/*
n = 5 (User Input)    x = (2 * n - 1)
Dimension of the matrix is (x * x)

1 2 3 4 5 6 7 8 9    row   sp  ep
-----------------    --------------  
5 5 5 5 5 5 5 5 5      1   1   9         (i, n, x)
5 4 4 4 4 4 4 4 5      2   2   8   sp => row
5 4 3 3 3 3 3 4 5      3   3   7   ep => x - row + 1
5 4 3 2 2 2 3 4 5      4   4   6
5 4 3 2 1 2 3 4 5    __5___5___5__
5 4 3 2 2 2 3 4 5      6   4   6
5 4 3 3 3 3 3 4 5      7   3   7   sp => x - row + 1
5 4 4 4 4 4 4 4 5      8   2   8   ep => row
5 5 5 5 5 5 5 5 5      9   1   9
-----------------    -------------- Tracing Table
*/
#include <iostream>
using namespace std;
int main() {
    int n, x, row, col, sp, ep, term;
    cout << "Please enter the value for n: ";
    cin >> n;
    x = (2 * n - 1);
    for (row = 1; row <= x; row++) {
        if (row > n) {
            sp = (x - row + 1);
            ep = row;
        } else {
            sp = row;
            ep = (x - row + 1);
        }
        term = n;
        for (col = 1; col <= x; col++) {
            cout << term << " ";
            if (col < sp) term--;
            else if (col >= ep) term++;
        }
        cout << endl;
    }

    cout << endl << "End of the program..." << endl;
    return 0;
}
