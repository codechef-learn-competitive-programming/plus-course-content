//C++ code to demonstrate tuple_size
#include<iostream>
#include<tuple> // for tuple_size and tuple
using namespace std;
int main() {
	// Initializing tuple
	tuple <char,int,float> mytuple(20,'g',17.5);

	// Use of size to find tuple_size of tuple
	cout << "The size of tuple is : ";
	cout << tuple_size<decltype(mytuple)>::value << endl;

	return 0;
}
