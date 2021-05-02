#include <iostream>
#include "26-MyHeader.h"
using namespace std;
int main() {
	int a, b, c;
	
	my_welcome();
	a = my_input();
	b = my_input();
	c = my_addition(a, b);
	my_display(c);
	my_goodbye();
	return 0;
}
	
