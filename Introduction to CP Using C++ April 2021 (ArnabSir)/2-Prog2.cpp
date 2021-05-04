#include <iostream>
// using namespace std;
int main() {
    int num1, num2, result;
    std::cout << "Please enter your first integer: ";
    std::cin >> num1;
    std::cout << "Please enter your second integer: ";
    std::cin >> num2;
    result = num1 + num2;
    std::cout << "So " << num1 << " + " << num2 << " = " << result << std::endl;

    std::cout << "End of the program..." << std::endl;
    return 0;
}
