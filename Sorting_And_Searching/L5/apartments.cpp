#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
int32_t main()
{
	FIO;
	int n, m, k; cin >> n >> m >> k;
	mk(a, n, int);
	mk(b, m, int);
 
	for (int i = 0; i < n; ++i)
		cin >> a[i];
 
	for (int i = 0; i < m; ++i)
		cin >> b[i];
 
	sort(a, a + n);
	sort(b, b + m);
 
	int j = 0;
	int ans = 0;
 
	for (int i = 0; i < n; ++i)
	{
		while (j < m && b[j] < a[i] - k)
			j++;
 
		//at this line
		if (j < m && b[j] <= a[i] + k)
			j++, ans++;
	}
 
	cout << ans << '\n';
 
	return 0;
}
