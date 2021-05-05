#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	void my_welcome(void);
	int my_input(void);
	int my_addition(int, int);
	void my_display(int);
	void my_goodbye(void);
	
	my_welcome();
	a = my_input();
	b = my_input();
	c = my_addition(a, b);
	my_display(c);
	my_goodbye();
}

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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
