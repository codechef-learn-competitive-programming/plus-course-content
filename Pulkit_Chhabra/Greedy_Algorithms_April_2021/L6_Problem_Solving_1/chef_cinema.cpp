#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main()
{
	FIO;
	w(t)
	{
		int n, m, z, l, r, b; cin >> n >> m >> z >> l >> r >> b;

		if (z + l + r >= n * m)
			cout << n*m << '\n';

		else
		{
			int bound1 = n * m - l - r - z;
			int bound2 = (n * (m + 1) - l - r) / 2;
			int bound3 = b;
			int bound4 = ((m + 1) / 2) * n;
			int b_max = min({bound1, bound2, bound3, bound4});

			cout << z + l + r + b_max << '\n';
		}
	}
	return 0;
}
