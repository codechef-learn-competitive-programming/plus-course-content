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
#define range(a,b)      substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)        cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int lower_bound_in_even(int *a, int n, int x)
{
	//smallest even id s.t. a[id] >= x
	int beg = 2, end = n, ans = -1;

	while (beg <= end)
	{
		int mid = (beg + end) / 2;

		if (mid & 1)
			mid--;

		if (a[mid] >= x)
			ans = mid, end = mid - 2;

		else
			beg = mid + 2;
	}

	return ans;
}

int32_t main()
{
	FIO;
	int n; cin >> n;
	mk(a, n + 1, int);

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	int t; cin >> t;

	int id = lower_bound_in_even(a, n, t);
	// smallest even index id s.t. a[id] >= target

	if (id == -1)
		cout << "No\n";

	else
	{
		if (a[id] == t or a[id - 1] == t)
			cout << "Yes\n";

		else
		{
			id2 = lower_bound_in_even(a, n, a[id - 1]);

			if (a[id2 - 1] != t)
				cout << "No\n";

			else
				cout << "Yes\n";
		}
	}
	return 0;
}
