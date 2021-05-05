#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector <int> vec;     // syntax for defining a vector
	// inserting elements into vector 
	cout << "Initializing the content of the vector" << endl;
	for (int i = 0; i < 6; i++) {
		vec.push_back((i+1) * 100);
	}
	
	// accessing the vector content
	cout << "Displaying the content of the vector" << endl << endl;
	// accessing using [] operator
	for(int i = 0; i < 6; i++)
		cout << vec[i] << " ";
	cout << endl << endl;
	
	// accessing using at()
	for(int i = 0; i < 6; i++)
		cout << vec.at(i) << " ";
	cout << endl << endl;
	
	// accessing using *iterator object
	for(auto it = vec.begin(); it != vec.end(); it++)
		cout << *(it) << " ";
	cout << endl << endl;
	
	// elements from end to start
	for(auto it = vec.rbegin(); it != vec.rend(); it++)
		cout << *(it) << " ";
	cout << endl << endl;
	
	// accessing using for-each loop
	for (int x : vec)
		cout << x << " ";
	cout << endl << endl;
	
	// returning the front element
	cout << "Front element is " << vec.front() << endl;
	// returning the last element
	cout << "Back element is " << vec.back() << endl;
	cout << "Size of the vector " << vec.size() << endl;
	cout << "Capacity of the vector " << vec.capacity() << endl;
	cout << "Max size of the vector " << vec.max_size() << endl;
	vec.resize(0);
	vec.empty()? cout << "Vector is empty..." << endl: 
				 cout << "Vector is not empty..." << endl;
	
	vec.reserve(10);
	cout << "Size of the vector " << vec.size() << endl;
	cout << "Capacity of the vector " << vec.capacity() << endl;
	vec.empty()? cout << "Vector is empty..." << endl: 
				 cout << "Vector is not empty..." << endl;
	cout << endl << "End of the program..." << endl;
	return 0;
}






