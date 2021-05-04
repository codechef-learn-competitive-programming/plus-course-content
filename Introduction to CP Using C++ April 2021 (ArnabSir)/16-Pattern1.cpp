/*
n = 6 (user input)     i   .   *
                     -------------
.....*                 1   5   1         (n, i)
....***                2   4   3    . => (n - i)
...*****               3   3   5
..*******              4   2   7    * => (2 * i - 1)
.*********             5   1   9
***********            6   0  11
                     -------------  Tracing table
*/
#include <iostream>
using namespace std;
int main() {
    int i, j, n;
    cout << "Please enter the number of layers: ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= (n - i); j++) {
            cout << ".";
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl << "End of the program..." << endl;
    return 0;

}