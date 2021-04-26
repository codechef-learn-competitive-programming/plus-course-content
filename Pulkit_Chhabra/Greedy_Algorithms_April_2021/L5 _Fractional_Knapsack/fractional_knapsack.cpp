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

bool comp(pii a, pii b)
{
	return a.ff * b.ss > b.ff * a.ss;
}

int32_t main()
{
	FIO;
	int n, cap; cin >> n >> cap;
	vector<pii> val_wt(n);

	for (int i = 0; i < n; ++i)
		cin >> val_wt[i].ff >> val_wt[i].ss;

	sort(val_wt.begin(), val_wt.end(), comp);

	double ans = 0;

	for (int i = 0; i < n; ++i)
	{
		int val = val_wt[i].ff, wt = val_wt[i].ss;

		if (cap >= wt)
			ans += val, cap -= wt;

		else
		{
			ans += (cap / (double)wt) * val;
			break;
		}
	}

	cout << ans << '\n';
	return 0;
}
