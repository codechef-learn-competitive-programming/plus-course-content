#include <iostream>
using namespace std;

int main(){

	int x = 10; 
	int &y = x;
	int* xy = &x;
	cout << xy << endl;
	cout << &y << endl; 
	cout << y << endl; 
	y++;
	cout<<x;

}