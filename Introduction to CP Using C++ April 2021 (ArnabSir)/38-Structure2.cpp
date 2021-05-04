#include <iostream>
using namespace std;
struct person {
    int age;
    int sal;
};

struct person person_init(void);
void person_display(struct person);

int main() {
    struct person p;

    p = person_init();
    person_display(p);

    cout << "End of the program...";
    return 0;
}

struct person person_init(void) {
    struct person pp;
    cout << "Initializing the structure variable..." << endl;
    cout << "Please enter the age of the person: ";
    cin >> pp.age;
    cout << "Please enter the salary of the person: ";
    cin >> pp.sal;
    return pp;
}

void person_display(struct person ppp) {
    cout << "Displaying the current content of the person..." << endl;
    cout << "So the age of the person is " << ppp.age << " and salary is " << ppp.sal << endl;
}