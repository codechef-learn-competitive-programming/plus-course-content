#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
//#define int             long long
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
	int n; cin >> n;
	int b = sqrt(n), sz = (n + b - 1) / b;

	vi arr(n);
	vector<vi> part(sz);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		part[i / b].pb(arr[i]);
	}

	for (int i = 0; i < sz; ++i)
		sort(part[i].begin(), part[i].end());

	w(q)
	{
		int tp; cin >> tp;

		if (tp == 0)
		{
			int l, r, k; cin >> l >> r >> k;
			l--, r--;

			int ans = 0;

			for (int i = l; i < min({n, (l / b + 1)*b, r + 1}); ++i)
				if (arr[i] >= k)
					ans++;

			if (r / b == l / b)
			{
				cout << ans << '\n';
				continue;
			}

			for (int i = (r / b) * b; i <= r; ++i)
				if (arr[i] >= k)
					ans++;

			for (int i = l / b + 1; i < r / b; ++i)
				ans += part[i].end() - lower_bound(part[i].begin(), part[i].end(), k);

			cout << ans << '\n';
		}

		else
		{
			int id, val; cin >> id >> val;
			id--;

			int i = id / b;

			for (int j = 0; j < part[i].size(); ++j)
				if (part[i][j] == arr[id])
				{
					arr[id] = val;
					part[i][j] = val;
					break;
				}

			sort(part[i].begin(), part[i].end());
		}
	}

	return 0;
}
