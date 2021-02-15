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
#define inf             3e18
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
		int n1, n2, n3; cin >> n1 >> n2 >> n3;

		vi v[3];

		while (n1--)
		{
			int x; cin >> x;
			v[0].pb(x);
		}

		while (n2--)
		{
			int x; cin >> x;
			v[1].pb(x);
		}

		while (n3--)
		{
			int x; cin >> x;
			v[2].pb(x);
		}

		for (int i = 0; i < 3; ++i)
			sort(v[i].begin(), v[i].end());

		int ans = inf;

		for (int i = 0; i < 3; ++i) // iterate over all 3 arrays
			for (int j = 0; j < v[i].size(); ++j)
			{
				int i1 = (i + 1) % 3, i2 = (i + 2) % 3;

				//i1 i i2
				//largest j1 s.t. v[i1][j1] <= v[i][j] // ub - 1
				//smallest j2 s.t. v[i2][j2] >= v[i][j] //lb

				auto it2 = lower_bound(v[i2].begin(), v[i2].end(), v[i][j]);
				auto it1 = upper_bound(v[i1].begin(), v[i1].end(), v[i][j]);

				//it2 != end and it1 != begin
				if (it2 != v[i2].end() and it1 != v[i1].begin())
				{
					it1--;
					int x = v[i][j], y = (*it1), z = (*it2);
					int cur = (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
					ans = min(ans, cur);
				}

				//i2 i i1
				it2 = upper_bound(v[i2].begin(), v[i2].end(), v[i][j]);
				it1 = lower_bound(v[i1].begin(), v[i1].end(), v[i][j]);

				if (it1 != v[i1].end() and it2 != v[i2].begin())
				{
					--it2;
					int x = v[i][j], y = (*it1), z = (*it2);
					int cur = (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
					ans = min(ans, cur);
				}
			}

		cout << ans << '\n';
	}
	return 0;
}
