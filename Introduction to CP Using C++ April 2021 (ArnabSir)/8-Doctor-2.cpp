#include <iostream>
using namespace std;
int main() {
    int day, medi, medi_count = 0;
    cout << "Visit to Doctor..." << endl;
    day = 1;
    do {
        cout << "Good morning..." << endl;
        medi = 1;
        while (medi <= 3) {
            cout << "Day number = " << day << " and medicine number = " << medi << endl;
            medi_count++;
            medi ++;
        }
        cout << "Good night..." << endl;
        cout << "-----------------------------------------------" << endl;
        day++;
    } while (day <= 5); 
    cout << "Thanks to Doctor..." << endl;
    cout << "Total number of medicines consumed is " << medi_count << endl;
}