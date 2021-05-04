#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> d{1,2,3,10,14};
	cout<<endl<<"Initialiiy d: ";
	for (int item:d) cout<<item<<", ";

	// push_back() O(1) for most of the time
	d.push_back(16);
	cout<<endl<<"After push_back() d: ";
	for (int item:d) cout<<item<<", ";

	// pop_back() / removes last element in O(!)
	d.pop_back();
	cout<<endl<<"After pop_back() d: ";
	for (int item:d) cout<<item<<", ";
	
	// insert some elements in the middle in O(N)
	d.insert(d.begin() + 3, 100);
	cout<<endl<<"After insert() d: ";
	for (int item:d) cout<<item<<", ";

	d.insert(d.begin() + 3, 4, 200);
	cout<<endl<<"After insert() of 4 elements of value 200 d: ";
	for (int item:d) cout<<item<<", ";
	
	// erase / delete some elements from the middle in O(N)
	d.erase(d.begin() + 2);
	cout<<endl<<"After delete() from d: "<<endl;
	for (int item:d) cout<<item<<", ";

	d.erase(d.begin() + 2, d.begin() + 5);
	cout<<endl<<"After delete() of elements at indices 2, 3 and 4 from d: "<<endl;
	for (int item:d) cout<<item<<", ";
	
	// size, capacity and resize
	cout<<endl<<"Size: "<<d.size();
	cout<<endl<<"Capacity: "<<d.capacity();
	d.resize(8); // if size increases then more memory will be allocated
	cout<<endl<<"After resize(): "<<endl;
	for (int item:d) cout<<item<<", ";

	cout<<endl<<"Size: "<<d.size();
	cout<<endl<<"Capacity: "<<d.capacity();
	
	// clear() removes all elements of the vector, but it does not 
	// release pre-occupied memory spaces
	d.clear();
    cout<<endl<<"Size: "<<d.size();
	cout<<endl<<"Capacity: "<<d.capacity();
	if (d.empty()) cout<<endl<<"This is an empty vector";
	
	// in push_back() most of the time the size of the vector will get doubled when the
	// spaces of the vector will get filled up. reserve() will keep a constant space 
	// from initial until the spaces are getting exhausted
	cout<<endl<<endl<<"Using method reserve()";
	vector <int> reserve_vector;
	reserve_vector.reserve(10);
	for(int i=0;i<5;i++) {
		reserve_vector.push_back((i+1)*10);
		cout<<endl<<"Size: "<<reserve_vector.size()<<" and Capacity: "<<reserve_vector.capacity();
	}
	
	return 0;
}
