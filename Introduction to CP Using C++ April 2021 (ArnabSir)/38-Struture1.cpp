#include <iostream>
using namespace std;
struct person {
    int age;
    int sal;
};
int main() {
    struct person p;

    cout << "Initializing the structure variable..." << endl;
    cout << "Please enter the age of the person: ";
    cin >> p.age;
    cout << "Please enter the salary of the person: ";
    cin >> p.sal;
    cout << "Displaying the current content of the person..." << endl;
    cout << "So the age of the person is " << p.age << " and salary is " << p.sal << endl;
    cout << "End of the program...";
    return 0;
}