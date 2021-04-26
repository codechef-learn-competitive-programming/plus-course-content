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

int max_cows(int k, vi &x)
{
	int n = x.size(), ans = 1, last_cow_pos = x[0];

	for (int i = 1; i < n; ++i)
	{
		if (x[i] - last_cow_pos >= k)
			ans++, last_cow_pos = x[i];
	}

	return ans;
}

int32_t main()
{
	FIO;
	w(t)
	{
		int n, c; cin >> n >> c;

		vi x(n);

		for (int &i : x)
			cin >> i;

		sort(x.begin(), x.end()); //don't forget

		int beg = 0, end = x[n - 1], ans;

		while (beg <= end)
		{
			int mid = (beg + end) / 2;

			if (max_cows(mid, x) >= c) //check if ans >= mid
				ans = mid, beg = mid + 1;
			else
				end = mid - 1;
		}

		cout << ans << '\n';
	}
	return 0;
}
