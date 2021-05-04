// N=6, H=5, Y1=1, Y2=2 and L=3.
// https://www.codechef.com/INPRG01/problems/PIPSQUIK
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, b;
    cin >> t;
    while (t--) {
        int n, h, y1, y2, l;
        b = 0;
        cin >> n >> h >> y1 >> y2 >> l;
        vector<pair<int, int>> v(n);
    	for(int i = 0; i < n; i++) {
    	    int t, x;
    	    cin >> t >> x;
    	    v[i].first = t;
    	    v[i].second = x;
    	}
    	for(int i = 0; i < n; i++) {
    	    if (l <= 0) break;
    	    if (v[i].first == 1) {
    	        if (h - y1 > v[i].second)  l--;
    	    } else {
    	        if (y2 < v[i].second) l--;
    	    }
    	    b++;
    	}
    	// If after breaking a barrier no life force is left, Edward gets 
    	// completely exhausted, unable to pass that barrier.
    	if (l == 0) b--;
    	cout << b << endl;
    }
    return 0;
}