#include <iostream>
using namespace std;
int a, b, c;           // global variable declaraion
int main() {
	void my_welcome(void);
	void my_input(int);
	void my_addition(void);
	void my_display(void);
	void my_goodbye(void);
	
	my_welcome();
	my_input(1);
	my_input(2);
	my_addition();
	my_display();
	my_goodbye();
}

void my_welcome(void) {
	cout << endl << "Welcome to the World of Programming...." << endl << endl;
}

void my_input(int turn) {
	cout << "Please enter a number -> ";
	if (turn == 1)
		cin >> a;	
	else
		cin >> b;
}

void my_addition(void) {
	cout << endl << "Performing the addition operation..." << endl;
	c = a + b;
}

void my_display() {
	cout << endl << "So the calculated sum is: " << c << endl;
}

void my_goodbye(void) {
	cout << endl << "End of the program..." << endl;
	cout << "Good bye..." << endl;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
