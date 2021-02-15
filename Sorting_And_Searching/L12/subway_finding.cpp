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
	//FIO;
	int n, k; cin >> n >> k;

	int beg = 1, end = n;

	while (true)
	{
		string s;

		if (end - beg <= 4 * k + 1)
		{
			int to_check = rng() % (end - beg + 1) + beg;
			cout << to_check << ' ' << to_check << '\n';
			cout.flush();

			cin >> s;

			if (s == "Yes")
				return 0;

			else
				beg = max(1ll, beg - k), end = min(n, end + k);
		}

		else
		{
			int mid = (beg + end) / 2;

			cout << beg << ' ' << mid << '\n';
			cout.flush();

			cin >> s;

			if (s == "Yes") // in [beg, mid]
				beg = max(1ll, beg - k), end = min(n, mid + k);

			else
				beg = max(1ll, mid + 1 - k), end = min(n, end + k);
		}
	}
	return 0;
}
