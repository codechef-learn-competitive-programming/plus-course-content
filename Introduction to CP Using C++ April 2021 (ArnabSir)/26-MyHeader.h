#include <iostream>
using namespace std;

void my_welcome(void) {
	cout << endl << "Welcome to the World of Programming...." << endl << endl;
}

int my_input(void) {
	int data;
	cout << "Please enter a number -> ";
	cin >> data;	
	return (data);
}

int my_addition(int x, int y) {
	int result;
	cout << endl << "Performing the addition operation..." << endl;
	result = x + y;
	return result;
}

void my_display(int r) {
	cout << endl << "So the calculated sum is: " << r << endl;
}

void my_goodbye(void) {
	cout << endl << "End of the program..." << endl;
	cout << "Good bye..." << endl;
}
		
