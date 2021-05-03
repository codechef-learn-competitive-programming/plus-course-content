#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// https://cses.fi/problemset/task/1648

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


void alter_point_update(vi &arr, vi &update, int &ans, int l, int r)
{
	int id = update[0], x = update[1];

	if (id >= l and id <= r)
		ans += x - arr[id];
}

void update_batch_point(vector<vi> &pending, vi &arr, vi &pre, int n)
{
	for (vi &up : pending)
		arr[up[0]] = up[1];

	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + arr[i];
}

int32_t main()
{
	FIO;
	int n; cin >> n;
	int q; cin >> q;

	vi arr(n + 1), pre(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	} //initial array and prefix sum is updated;

	int b = sqrt(q) + 1, cur_b = 0;

	// After answering each query
	// Check if current query if the last query of this block
	vector<vi> pending;

	vi done(n + 1);
	// This is important because there can be multiple updates
	// for same index

	for (int i = 0; i < q; ++i)
	{
		int tp; cin >> tp;

		if (tp == 1) // point update vali
		{
			int id, x; cin >> id >> x; // arr[id] = x;
			pending.pb({id, x});
		}

		else
		{
			int l, r; cin >> l >> r;
			int ans = pre[r] - pre[l - 1];

			for (int i = pending.size() - 1; i >= 0; --i)
				if (!done[pending[i][0]])
				{
					alter_point_update(arr, pending[i], ans, l, r);
					done[pending[i][0]] = 1;
				}

			for (vi &update : pending)
				done[update[0]] = 0;

			cout << ans << '\n';
		}

		// Check if 'i' is the last index in this block
		if (i == cur_b * b + b - 1)
		{
			update_batch_point(pending, arr, pre, n);
			pending.clear();
			cur_b++;
		}
	}

	return 0;
}
