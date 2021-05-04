// pointers to structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct attributes {
    string name;
    string color;
};

struct fruit {
    attributes details;
    int price;
};

int main () {
    fruit fr;
    fruit *frptr;
    frptr = &fr;
    string frcolor;

    cout << "Enter the fruit name: ";
    getline (cin, frptr->details.name);
    cout << "Enter the fruit color: ";
    getline (cin, frcolor);
    (stringstream) frcolor >> frptr->details.color;
    cout << "Enter the fruit price: ";
    cin >> fr.price;

    cout << "\nYou have entered:\n";
    cout << "Fruit name: " << frptr->details.name << endl;
    cout << "Fruit color: " << fr.details.color << endl;
    cout << "Fruit price: " << frptr->price << endl;
    cout << "End of the program..." << endl;

    return 0;
}