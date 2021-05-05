// array of structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct fruit {
    string name;
    int price;
} fruits [3];

void printFruit (fruit);

int main () {
    string frprice;
    int pr;

    for (int n = 0; n < 3; n++) {
        cout << "Enter fruit title: ";
        getline (cin, fruits[n].name);
        cout << "Enter fruit price: ";
        getline (cin, frprice);
        stringstream(frprice) >> fruits[n].price;
    }

    cout << endl << "You have entered these fruit details:" << endl;
    for (int n = 0; n < 3; n++)
        printFruit (fruits[n]);
    return 0;
}

void printFruit(fruit fr) {
  cout << "Fruit name = " << fr.name << " and fruit price = " << fr.price << endl;
}