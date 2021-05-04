#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector <int> vec1;
    vector <int> vec2;

    cout << endl << "Initializing both the vectors..." << endl;
    for (int i=0;i<6;i++) {
        vec1.push_back((i + 1) * 11);
    }
    for (int i=0;i<6;i++) {
        vec2.push_back((i + 1) * 100);
    }
    cout << endl << "So the initial content of the vectors are..." << endl;
    for (int x: vec1) {
        cout << x << ", ";
    }
    cout << endl;
    for (int x: vec2) {
        cout << x << ", ";
    }
    cout << endl;
    cout << endl << "Swapping two vectors..." << endl;
    swap(vec1, vec2);
    cout << endl << "So the final content of the vectors are..." << endl;
    for (int x: vec1) {
        cout << x << ", ";
    }
    cout << endl;
    for (int x: vec2) {
        cout << x << ", ";
    }
    cout << endl;
    cout << endl << "End of the program..." << endl;
    return 0;
}