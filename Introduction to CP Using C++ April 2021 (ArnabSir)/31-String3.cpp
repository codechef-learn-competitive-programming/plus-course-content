// Returns an iterator positioned at the
// first character in a string

#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "C++ is best computer language";

    string::iterator It = str.begin();

    while ( It != str.end() )
    {
    	if ( *It == ' ' )
    		*It = '\n';
    	cout << *It++;
    }
    cout << endl;
    
    return 0;
}