//C++ code to demonstrate swap()
#include<iostream>
#include<tuple> // for swap() and tuple
using namespace std;
int main() {
	// Initializing 1st tuple
	tuple <int,char,float> tup1(20,'g',17.5);
	
	// Initializing 2nd tuple
	tuple <int,char,float> tup2(10,'f',15.5);
	
	// Printing 1st and 2nd tuple before swapping
	cout << "The first tuple elements before swapping are : ";
	cout << get<0>(tup1) << " " << get<1>(tup1) << " "
		<< get<2>(tup1) << endl;
	cout << "The second tuple elements before swapping are : ";
	cout << get<0>(tup2) << " " << get<1>(tup2) << " "
		<< get<2>(tup2) << endl;
	
	// Swapping tup1 values with tup2
	tup1.swap(tup2);
	
	// Printing 1st and 2nd tuple after swapping
	cout << "The first tuple elements after swapping are : ";
	cout << get<0>(tup1) << " " << get<1>(tup1) << " "
		<< get<2>(tup1) << endl;
	cout << "The second tuple elements after swapping are : ";
	cout << get<0>(tup2) << " " << get<1>(tup2) << " "
		<< get<2>(tup2) << endl;

	return 0;
}
