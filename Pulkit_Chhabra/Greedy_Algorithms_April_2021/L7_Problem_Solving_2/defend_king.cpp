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
		int n, m, towers; cin >> n >> m >> towers;

		vi r(towers), c(towers);

		for (int i = 0; i < towers; ++i)
			cin >> r[i] >> c[i];

		//adjacent k differences ka max
		r.pb(0), r.pb(n + 1), c.pb(0), c.pb(m + 1);

		sort(r.begin(), r.end());
		sort(c.begin(), c.end());

		int max_r = 0, max_c = 0;

		n = r.size(), m = c.size();

		for (int i = 1; i < n; ++i)
			max_r = max(r[i] - r[i - 1] - 1, max_r);

		for (int i = 1; i < m; ++i)
			max_c = max(c[i] - c[i - 1] - 1, max_c);

		cout << max_r*max_c << '\n';
	}
	return 0;
}
