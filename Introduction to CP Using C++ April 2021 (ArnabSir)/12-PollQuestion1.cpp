#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str ("This.is.a.horse");
        str.erase (str.begin()+ 5, str.end()-7);
        cout << str << endl;


} 