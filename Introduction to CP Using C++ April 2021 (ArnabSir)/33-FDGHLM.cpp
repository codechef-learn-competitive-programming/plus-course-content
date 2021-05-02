// https://www.codechef.com/INPRG01/problems/FDGHLM
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b > a) 
        gcd (b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    long int l = (long int) a * b / g;
    cout << g << " " << l << endl;
    return 0;
}