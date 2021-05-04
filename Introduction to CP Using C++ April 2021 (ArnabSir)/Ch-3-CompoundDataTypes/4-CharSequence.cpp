#include <iostream>
using namespace std;

void display(char *);        // Prototype declaration...
void display(string);

int main() {
    string str1;
    char str[100];
    char msg1[4] = "C++";
    char msg2[] = {'C','+','+','\0'};
    char msg3[4] = {'C','+','+','\0'};
    cout << msg1 << ", " << msg2 << " and " << msg3 << endl;

    cout << "Enter a string: ";
    getline(cin, str1);

    cout << "Enter another string: ";
    cin.get(str, 100, '\n');

    display(str1);
    display(str);
    return 0;
}

void display(char s[]) {
    cout << "Entered char array is: " << s << endl;
}

void display(string s) {
    cout << "Entered string is: " << s << endl;
}