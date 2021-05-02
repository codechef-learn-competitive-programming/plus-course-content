// total =    1 + 2 + 3 + 4 + 10 + 5 + 6 + 7 + 8 + 26 + 9 + 10 + ... n terms
// place no.  1   2   3   4   5    6   7   8   9   10   11  12 .... 
// What will be the 99th term of the series?
#include <iostream>
using namespace std;
int main() {
    int n, term = 1, final_sum = 0, temp_sum = 0, i;
    cout << "Please enter the number of terms: ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        if (i % 5 == 0) {
            final_sum += temp_sum;
            cout << "For i = " << i << " adding temp_sum = " << temp_sum << endl;
            temp_sum = 0;
        } else {
            final_sum += term;
            cout << "For i = " << i << " adding term = " << term << endl;
            temp_sum += term;
            term++;
        }
    }
    cout << endl << "So the final sum = " << final_sum << endl;
    cout << "End of the program..." << endl;
    return 0;
}