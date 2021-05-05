// array passed as parameter
#include <iostream>
using namespace std;
void printArray(int [], int);    // function prototype declaration...
int main() {
    int firstArray[] = {11, 22, 33, 44, 55};
    int secondArray[] = {100, 200, 300, 400};
    printArray(firstArray, 5);
    printArray(secondArray, 4);
    cout << endl << "End of the program..." << endl;
    return 0;
}

void printArray(int arr[], int length) {
    for (int n = 0; n < length; n++) {
        cout << arr[n] << ", ";
    }
    cout << endl;
}