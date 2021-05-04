#include <iostream>
using namespace std;
// void my_display(int);   // global declaration of the function prototype
int main() {
	int a, b, c;
	void my_welcome(void);
	int my_input(void);
	void my_addition(int, int);
	void my_goodbye(void);
	
	my_welcome();
	a = my_input();
	b = my_input();
	my_addition(a, b);
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

void my_display(int r) {
	cout << endl << "So the calculated sum is: " << r << endl;
}

void my_addition(int x, int y) {
	int result;
	cout << endl << "Performing the addition operation..." << endl;
	result = x + y;
	my_display(result);
}

void my_goodbye(void) {
	cout << endl << "End of the program..." << endl;
	cout << "Good bye..." << endl;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
