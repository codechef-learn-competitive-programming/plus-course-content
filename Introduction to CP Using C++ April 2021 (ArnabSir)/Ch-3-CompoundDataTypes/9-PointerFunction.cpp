// pointer to functions
#include <iostream>
using namespace std;

int addition (int a, int b) {
    return (a + b);
}

int subtraction (int a, int b) {
    return (a - b);
}

int operation (int x, int y, int (*functocall)(int, int)) {
    int result;
    result = (*functocall)(x, y);
    return (result);
}

int main () {
    int result1, result2;
    int (*minus)(int, int) = subtraction;
    result1 = operation (7, 5, addition);
    cout << "So 7 + 5 = " << result1 << endl; 
    result2 = operation (20, result1, minus);
    cout << "So 20 - " << result1 << " = " << result2 << endl;
    return 0;
}