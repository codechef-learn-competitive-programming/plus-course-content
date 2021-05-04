/*
n = 11 (ODD Input)     i   .   *         m = (n + 1) / 2 = 6
                     -------------
***********            1   0  11         (n, m, i)
.*********             2   1   9    . => (i - 1)
..*******              3   2   7
...*****               4   3   5    * => 2 * (m - i) + 1
....***                5   4   3
.....*               __6___5___1__
....***                7   4   3
...*****               8   3   5    . => (n - i)
..*******              9   2   7 
.*********            10   1   9    * => 2 * (i - m) + 1
***********           11   0  11
                     -------------  Tracing table
*/
#include <iostream>
using namespace std;
int main() {
    int i, j, n, s, b, m;
    /* do {
        cout << "Please enter the odd number of layers: ";
        cin >> n;
    } while (n % 2 == 0); */

    while (1) {
        cout << "Please enter the odd number of layers: ";
        cin >> n;
        if (n % 2 == 1) break;
    }
    
    m = (n + 1) / 2;
    for (i = 1; i <= n; i++) {
        if (i > m) {
            b = n - i;
            s = 2 * (i - m) + 1;
        } else {
            b = i - 1;
            s = 2 * (m - i) + 1;
        }
        for (j = 1; j <= b; j++) {
            cout << ".";
        }
        for (j = 1; j <= s; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl << "End of the program..." << endl;
    return 0;

}