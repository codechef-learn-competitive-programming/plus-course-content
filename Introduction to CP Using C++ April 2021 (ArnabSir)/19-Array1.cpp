#include <iostream>
using namespace std;
int main() {
    int a[] = {16, 2, 77, 40, 50};
    int max, min, total = 0, count = 5;

    cout << "Displaying the content of the array" << endl;
    for(int i = 0; i < count; i++) {
        cout << "Location number: " << i << " and Content: " << a[i] << endl;
        if (i == 0) {
            max = a[i]; min = a[i];
        } else {
            if (max < a[i]) {max = a[i];}
            if (min > a[i]) {min = a[i];}
        }
        total = total + a[i];
    }

    cout << "So maximum value: " << max << " and minimum value: " << min << endl;
    cout << "So total: " << total << " and average: " << total / count << endl;
    cout << "End of the program..." << endl;
}