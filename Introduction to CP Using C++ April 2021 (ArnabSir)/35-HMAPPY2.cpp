
// https://www.codechef.com/UACPP01/problems/HMAPPY2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n, a, b, k;
        cin >> n >> a >> b >> k;
        long long int x = n / a; 
        long long int y = n / b;       
        long long int lcm = (a * b)/__gcd(a, b);
        long long int z = (n / lcm) * 2;
        if ((x + y - z) >= k)
            cout << "Win" << endl;
        else
            cout << "Lose" << endl;
    }
    return 0;
}
