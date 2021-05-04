// C++ code to demonstrate working of tie()
#include<iostream>
#include<tuple> // for tie() and tuple
using namespace std;
int main() {
	// Initializing variables for unpacking
	int i_val;
	char ch_val;
	float f_val;
	
	// Initializing tuple
	tuple <int,char,float> tup1(20,'g',17.5);

	// Use of tie() without ignore
	tie(i_val,ch_val,f_val) = tup1;
	
	// Displaying unpacked tuple elements
	// without ignore
	cout << "The unpacked tuple values (without ignore) are : ";
	cout << i_val << " " << ch_val << " " << f_val;
	cout << endl;
	
	// Use of tie() with ignore
	// ignores char value
	tie(i_val,ignore,f_val) = tup1;
	
	// Displaying unpacked tuple elements
	// with ignore
	cout << "The unpacked tuple values (with ignore) are : ";
	cout << i_val << " " << f_val;
	cout << endl;

	return 0;
}
