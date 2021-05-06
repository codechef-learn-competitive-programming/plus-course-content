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

int get(int n)
{
	n %= mod;
	return (n * (n + 1) / 2) % mod;
}

// https://cses.fi/problemset/view/1082/

int32_t main()
{
	FIO;
	int n; cin >> n;
	int sq = sqrt(n), ans = 0, not_inc;

	// when i > sq, (n/i) will be < sq
	// what if I count for each different
	// value of n/i, sum of i's s.t.
	// num_of_numbers_having_i_as_divisor = this value

	for (int frq = 1; frq <= sq; ++frq)
	{
		// floor(n/i) = frq
		// -> n/i >= frq, n/i < frq + 1
		// -> i <= n/frq, i > n/(frq+1)

		int i_sum = get(n / frq) - get(n / (frq + 1)) + mod;
		not_inc = n / (frq + 1);
		int cur = (frq * i_sum) % mod;

		ans = (ans + cur) % mod;
	}

	for (int i = 1; i <= not_inc; ++i) // ans += i * num_of_numbers_having_i_as_divisor
		ans += i * (n / i), ans %= mod;

	cout << ans << '\n';
	return 0;
}
