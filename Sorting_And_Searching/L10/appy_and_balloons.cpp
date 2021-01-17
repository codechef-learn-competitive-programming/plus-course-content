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


bool ans_possible(int k, int *a, int *b, int n, int balloons_we_have)
{
	int min_balloons_required = 0;

	for (int i = 0; i < n; ++i)
	{
		int ceil_of_exp = (a[i] * b[i] - k + b[i] - 1) / b[i]; //ceil(a*b - k)/b;
		int cur_min_ball = max(0ll, ceil_of_exp);

		min_balloons_required += cur_min_ball;
	}

	return min_balloons_required <= balloons_we_have;
}

int32_t main()
{
	FIO;
	int n, balloons_we_have; cin >> n >> balloons_we_have;

	mk(req_balloons, n, int);
	mk(candies_per_bal, n, int);

	for (int i = 0; i < n; ++i)
		cin >> req_balloons[i];

	for (int i = 0; i < n; ++i)
		cin >> candies_per_bal[i];

	//smallest such k s.t. it is possible to have max(ci) <= k
	int beg = 0, end = inf, ans;

	while (beg <= end)
	{
		int mid = (beg + end) / 2;

		if (ans_possible(mid, req_balloons, candies_per_bal, n, balloons_we_have))
			ans = mid, end = mid - 1;

		else
			beg = mid + 1;
	}

	cout << ans << '\n';

	return 0;
}
