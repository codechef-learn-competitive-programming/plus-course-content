// C++ program to create Set of Pairs
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairs;

// Constant reference
// reference for speed const to avoid changing values
void display(const set<pairs>& s) {
	bool found = false;

	// range-based for loop
	for (auto const &x : s) {
		found = true;
		cout << "(" << x.first << ", "
			<< x.second << ")"
			<< " ";
	}

	if (not found) {
		cout << "No valid pair\n";
	}
}
int main() {
	vector<int> v{ 2, 3, 1, 6, 8, 8, 10, 2 };
	set<pairs> s;
	
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {

			// check for even number
			if (v[i] % 2 == 0 && v[j] % 2 == 0) {

				// makes pairs of even numbers
				pairs x = make_pair(v[i], v[j]);

				// inserts into the set
				s.insert(x);
			}
		}
	}

	// to display the pairs
	display(s);

	// to clear the set
	s.clear();

    cout << endl;
}

/*
Set is a C++ STL container used to store the unique elements, 
and all the elements are stored in a sorted manner.
Once the value is stored in the set, it cannot be modified within the set; 
instead, we can remove this value and can add the modified value of the element.
Sets are implemented using Binary search trees.
*/