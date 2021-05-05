// C++ code to demonstrate working of tuple_cat()
#include<iostream>
#include<tuple> // for tuple_cat() and tuple
using namespace std;
int main() {
	// Initializing 1st tuple
	tuple <int,char,float> tup1(20,'g',17.5);

	// Initializing 2nd tuple
	tuple <int,char,float> tup2(30,'f',10.5);
	
	// Concatenating 2 tuples to return a new tuple
	auto tup3 = tuple_cat(tup1,tup2);
	
	// Displaying new tuple elements
	cout << "The new tuple elements in order are : ";
	cout << get<0>(tup3) << " " << get<1>(tup3) << " ";
	cout << get<2>(tup3) << " " << get<3>(tup3) << " ";
	cout << get<4>(tup3) << " " << get<5>(tup3) << endl;

	return 0;
}
