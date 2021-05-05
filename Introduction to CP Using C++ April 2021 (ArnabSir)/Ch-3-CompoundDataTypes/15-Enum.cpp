#include <iostream>
using namespace std;

enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
enum seasons { spring = 34, summer = 4, autumn = 9, winter = 32};
enum suit { club = 0, diamonds = 10, hearts = 20, spades = 3 } card;
enum class Colors {black, blue, green, cyan, red, purple, yellow, white};
// Enumerated types with enum class

int main() {
    week today;
    today = Wednesday; cout << "Wednesday " << today << endl;
    today = Thursday; cout << "Thursday " << today << endl;
    today = Saturday; cout << "Saturday " << today << endl;

    seasons s;
    s = summer; cout << "Summer " << s << endl;
    s = winter; cout << "Winter " << s << endl;

    card = club;
    cout << "Size of enum variable " << sizeof(card) << " bytes." << endl;
    card = diamonds; cout << "Diamond " << card << endl;
    card = club; cout << "Club " << card << endl;

    Colors mycolor;
    mycolor = Colors::blue; 
    cout << "Mycolor " << sizeof(mycolor) << ", " << int(mycolor) << endl;
    if (mycolor == Colors::blue) mycolor = Colors::red;
    cout << "Mycolor " << sizeof(mycolor) << ", " << int(mycolor) << endl;

    return 0;
}