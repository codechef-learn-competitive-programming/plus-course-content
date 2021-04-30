#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	int n = 5;
	float* ptr;

	ptr = new float[n];

	for(int i = 0; i < n; i++){
		cin >> *(ptr + i);
	}

	for(int i = 0; i < n; i++){
		cout << *(ptr + i) << endl;
	}

	delete[] ptr;
	return 0;
}