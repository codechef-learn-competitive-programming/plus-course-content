// https://www.codechef.com/INPRG01/problems/PREFMAX
#include <iostream>
using namespace std;
int main() {
    long long int x, n, m, ans;
    cout << 2 << endl;
    cin >> n;
    ans = 1;
    cin >> m;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        if (x > m) {
            ans += 1;
            m = x;
        }
    }
    cout << ans;       
}