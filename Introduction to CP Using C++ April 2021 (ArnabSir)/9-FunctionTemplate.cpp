// function template
#include <iostream>
using namespace std;

template <class T> 
T sum (T a, T b) {
    T result;
    result = a + b;
    return result;
}

template <class T, class U>
bool are_equal (T a, U b) {
  return (a == b);
}

// Non-type template arguments
template <class T, int N>
T fixed_multiply (T val) {
    return val * N;
}

int main () {
    int i = 5, j = 6, k;
    double f = 5.5, g = 6.0, h;
    k = sum<int>(i, j);
    h = sum<double>(f, g);
    cout << k << endl;
    cout << h << endl;
    if (are_equal(10, 10.0))    // are_equal(10, true)
        cout << 10 << " and " << 10.0 << " are equal" << endl;
    else
        cout << 10 << " and " << 10.0 << " are not equal" << endl;
    cout << fixed_multiply<int, 2>(10) << endl;
    cout << fixed_multiply<double, 3>(10.5) << endl;
    return 0;
}