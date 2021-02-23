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
#define mod             1000000009
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
	string s; cin >> s;
	int n = s.length();

	vector<vi> hash(n, vi(n));

	for (int i = 0; i < n; ++i)
	{
		hash[i][i] = s[i] - 'a';
		for (int j = i + 1; j < n; ++j)
		{
			int d = s[j] - 'a';
			hash[i][j] = (31 * hash[i][j - 1] + d) % mod;
		}
	}

	pii ans = { -1, -1};

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; j += 2)
		{
			int m = (i + j) / 2;
			if (hash[i][m] == hash[m + 1][j] and j - i + 1 > ans.ss - ans.ff + 1)
				ans = {i, j};
		}

	cout << ans.ff << ' ' << ans.ss << '\n';

	return 0;
}
