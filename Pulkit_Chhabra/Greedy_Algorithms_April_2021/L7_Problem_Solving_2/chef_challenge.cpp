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

int sum(int n)
{
	return (n * (n + 1)) / 2;
}

int32_t main()
{
	FIO;
	w(T)
	{
		int n, k; cin >> n >> k;
		map<int, vi> idvals;

		bool poss = 0;
		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			idvals[x].pb(i);

			if (idvals[x].size() >= k)
				poss = 1;
		}

		if (!poss)
		{
			cout << -1 << '\n';
			continue;
		}

		int ans = inf;

		for (auto &p : idvals)
		{
			vi &v = p.ss;

			if (v.size() < k)
				continue;

			vi pre;

			for (int i = 0; i < v.size(); ++i)
				if (pre.empty())
					pre.pb(v[i]);
				else
					pre.pb(pre.back() + v[i]);

			for (int l = 0; l + k - 1 < v.size(); l++)
			{
				int r = l + k - 1, mid = (l + r) / 2;

				int summation_left = sum(mid) - sum(l - 1) - pre[mid];

				if (l)
					summation_left += pre[l - 1];

				int left_cost = (mid - l + 1) * (v[mid] - mid) + summation_left;

				int summation_right = pre[r] - pre[mid] + sum(mid) - sum(r);
				int right_cost = (r - mid) * (mid - v[mid]) + summation_right;

				ans = min(ans, left_cost + right_cost);
			}
		}

		cout << ans << '\n';
	}

	// left -> v[mid] - mid + i - v[i]
	// rigt -> v[i] - i + mid - v[mid]
	return 0;
}
