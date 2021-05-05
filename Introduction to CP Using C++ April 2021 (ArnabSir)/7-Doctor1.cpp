#include <iostream>
using namespace std;
int main() {
    int day, medi, medi_count = 0;
    cout << "Visit to Doctor..." << endl;
    for (day = 1; day <= 5; day++) {
        cout << "Good morning..." << endl;
        for (medi = 1; medi <= 3; medi ++) {
            cout << "Day number = " << day << " and medicine number = " << medi << endl;
            medi_count++;
        }
        cout << "Good night..." << endl;
        cout << "-----------------------------------------------" << endl;
    }
    cout << "Thanks to Doctor..." << endl;
    cout << "Total number of medicines consumed is " << medi_count << "\n";
}