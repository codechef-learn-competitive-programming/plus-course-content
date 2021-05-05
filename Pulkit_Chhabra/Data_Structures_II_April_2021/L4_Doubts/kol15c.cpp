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
	int n, q; cin >> n >> q;
	int sq = sqrt(n);

	vi arr(n + 1), inc(n + 1);
	map<int, vi> batch;

	while (q--)
	{
		int st, jump; cin >> jump >> st;

		if (jump > sq)
			for (int i = st; i <= n; i += jump)
				arr[i]++;

		else
			inc[st]++, batch[jump].pb(st);
	}

	for (auto &p : batch)
	{
		vi inc(n + 1);
		for (int st : p.ss)
			inc[st]++;

		for (int i = p.ff + 1; i <= n; ++i)
			inc[i] += inc[i - p.ff];

		for (int i = 1; i <= n; ++i)
			arr[i] += inc[i];
	}

	for (int i = 1; i <= n; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
	return 0;
}
