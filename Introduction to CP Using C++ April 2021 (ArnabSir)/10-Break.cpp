#include <iostream>
using namespace std;
int main() {
    int i;

    for (i = 1; i <= 10; i++) {
        if (i == 8) {
            cout << "Executing the break statement..." << endl;
            break;
        }
        cout << "Executing for i = " << i << endl;
    }

    cout << endl << "End of the program..." << endl;
}