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
#define pqb             priority_queue<vi>
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
	vi a(n), b(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		cin >> b[i];
	map<pii, int> done;
	pqb q;

	q.push({a[n - 1] + b[n - 1], n - 1, n - 1});
	done[ {n - 1, n - 1}] = 1;

	int ans;

	while (k--)
	{
		auto tp = q.top();
		q.pop();

		ans = tp[0];
		int i = tp[1], j = tp[2];

		if (i and !done[ {i - 1, j}])
			q.push({a[i - 1] + b[j], i - 1, j}), done[ {i - 1, j}] = 1;

		if (j and !done[ {i, j - 1}])
			q.push({a[i] + b[j - 1], i, j - 1}), done[ {i, j - 1}] = 1;
	}

	cout << ans << '\n';
	return 0;
}
