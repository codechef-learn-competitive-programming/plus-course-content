// This is a single line comment
/*
This is a 
block comment
containing multiple lines... */
#include <iostream>
using namespace std;
/* A namespace is a declarative region that provides a scope to the identifiers
(names of function, variables, labels etc.) inside it. */
/* All the entities (variables, types, constants and functions) of the standard C++
library are declared within the std namespace. So we include it at the beginning
of our code. */
int main() {
    int num1, num2, result;
    std::cout << "Please enter your first integer: ";
    std::cin >> num1;
    cout << "Please enter your second integer: ";
    cin >> num2;
    result = num1 + num2;
    cout << "So " << num1 << " + " << num2 << " = " << result << std::endl;

    std::cout << "End of the program..." << endl;
    return 0;
}
