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
#define ld				long double
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int f(int n) //range of n can be between 1 and 4 * 10^18
{
	int beg = 1, end = min(n, (int)2e9), ans;

	while (beg <= end) //largest val s.t. val*val <= n
	{
		int mid = (beg + end) / 2;

		//cout << mid << ' ' << mid*mid << '\n';

		if (mid * mid <= n)
			ans = mid, beg = mid + 1;

		else
			end = mid - 1;
	}

	return ans;
}

ld f2(int n, int p)
{
	ld beg = 1.0, end = min((ld)n, (ld)2e9);
	ld range_of_p = pow(10, -p);

	while (end - beg > range_of_p)
	{
		ld mid = (beg + end) / 2.0;

		cout << ps(beg, 5) << ' ' << end << ' ' << mid << '\n';

		if (mid * mid <= n)
			beg = mid;

		else
			end = mid;
	}

	return end;
}

int32_t main()
{
	FIO;
	int n, p; cin >> n >> p;
	ld ans = f2(n, p);

	cout << ps(ans, p) << '\n';
	return 0;
}
