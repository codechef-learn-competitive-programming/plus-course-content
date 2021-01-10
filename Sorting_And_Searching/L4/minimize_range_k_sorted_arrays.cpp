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
#define pqs             priority_queue<vi,vector<vi>,greater<vi> >
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
	int n, k; cin >> n >> k;

	mk(arr, k, vi);

	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int x; cin >> x;
			arr[i].pb(x);
		}
	}

	int mx = 0, ans = inf;
	vi ids(k);

	pqs s;

	for (int i = 0; i < k; ++i)
		s.push({arr[i][0], i}), mx = max(mx, arr[i][0]);

	while (true)
	{
		auto minElement = s.top();
		s.pop();

		int mn = minElement[0], ar_id = minElement[1];

		ans = min(ans, mx - mn);

		if (ids[ar_id] == n - 1)
			break;

		else
		{
			ids[ar_id]++;
			int next_val = arr[ar_id][ids[ar_id]];
			s.push({next_val, ar_id});
			mx = max(mx, next_val);
		}
	}

	cout << ans << '\n';
	return 0;
}
