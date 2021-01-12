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

int max_by_cook(int rank, int time_allowed)
{
	int beg = 0, end = time_allowed, ans;

	while (beg <= end) //Binary Searching for max. number of paratas possible to be cooked within t seconds
	{
		int mid = (beg + end) / 2;

		int time_for_mid = (rank * (mid + 1) * mid) / 2; //4 * (4e6) * (4e6) -> 6.4e13

		if (time_for_mid <= time_allowed)
			ans = mid, beg = mid + 1;

		else
			end = mid - 1;
	}

	return ans;
}

int max_paratas(int t, int *r, int n)
{
	int total_paratas = 0;

	for (int i = 0; i < n; ++i)
		total_paratas += max_by_cook(r[i], t);

	return total_paratas;
}

int32_t main()
{
	FIO;
	w(t)
	{
		int p; cin >> p;
		int n; cin >> n;
		mk(r, n, int);

		for (int i = 0; i < n; ++i)
			cin >> r[i];

		int beg = 0, end = (r[0] * p * (p + 1)) / 2, ans;

		while (beg <= end) //binary search for minimum reqd time
		{
			int mid = (beg + end) / 2;

			if (max_paratas(mid, r, n) >= p)
				ans = mid, end = mid - 1;

			else
				beg = mid + 1;
		}

		cout << ans << '\n';
	}
	return 0;
}
