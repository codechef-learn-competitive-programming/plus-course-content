#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
//#define int             long long
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

int zero;
vi sq;

void pre()
{
	for (int i = 0; i <= 5000; ++i)
		sq.pb(i * i);
}

int32_t main()
{
	FIO;
	int tc; cin >> tc;
	pre();

	int *cnt = new int[20000001];

	for (int i = 0; i < 20000001; ++i)
		cnt[i] = 0;

	for (int tnum = 1; tnum <= tc; ++tnum)
	{
		int n; cin >> n;
		zero = 100 * n;
		int sz = 200 * n + 1;

		cnt[zero]++;
		int cur = 0;
		long long ans = 0;

		mk(arr, n, int);

		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			cur += x;
			arr[i] = cur;

			for (int num : sq)
			{
				if (num > 100 * n)
					break;

				int id = cur - num + zero;

				if (id >= 0 && id < sz)
					ans += (long long)cnt[id];
			}

			cnt[zero + cur]++;
		}

		for (int i = 0; i < n; ++i)
			cnt[zero + arr[i]] = 0;

		cnt[zero] = 0;

		cout << "Case #" << tnum << ": " << ans << '\n';
	}
	return 0;
}
