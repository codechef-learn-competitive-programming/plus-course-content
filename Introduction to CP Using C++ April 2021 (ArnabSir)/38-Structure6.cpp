#include <iostream>
using namespace std;
typedef struct {
    int dd;
    int mm;
    int yy;
} date;
typedef struct {
    int age;
    int *sal;
    date doj;               // Structure in structure
} person;

void person_init(person *);
void person_display(person);

int main() {
    person p;

    if ((p.sal = (int *) malloc(sizeof(int))) == NULL) {
        cout << "No memory to allocate buffer..." << endl;
        return 1;
    }

    person_init(&p);     // call by reference or clear passing address as a value.
    person_display(p);   // call by value

    cout << "End of the program...";
    return 0;
}

void person_init(person *pp) {    // structure pointer variable
    cout << "Initializing the structure variable..." << endl;
    cout << "Please enter the age of the person: ";
    cin >> (*pp).age;
    cout << "Please enter the salary of the person: ";
    cin >> *pp->sal;
    cout << "Please enter the date of joining of the person: ";
    cin >> pp->doj.dd;
    cout << "Please enter the month of joining of the person: ";
    cin >> pp->doj.mm;
    cout << "Please enter the year of joining of the person: ";
    cin >> pp->doj.yy;
}

void person_display(person ppp) {
    cout << "Displaying the current content of the person..." << endl;
    cout << "So the age of the person is " << ppp.age << " and salary is " << *ppp.sal << endl;
    cout << "So date: " << ppp.doj.dd << ", month: " << ppp.doj.mm <<
                                " and year: " << ppp.doj.yy << "..." << endl;
}