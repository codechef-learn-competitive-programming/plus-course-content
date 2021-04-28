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

int get_next(vi &one, vi &two)
{
	int from_two = two.size() ? two.back() : 0;
	int from_one = 0;

	if (one.size())
		from_one = one.back();

	if (one.size() >= 2)
		from_one += one[one.size() - 2];

	if (from_one > from_two)
	{
		one.pop_back();

		if (one.size())
			one.pop_back();

		return from_one;
	}

	two.pop_back();
	return from_two;
}

int32_t main()
{
	FIO;
	int n, cap = 0; cin >> n;
	vi one, two;

	for (int i = 0; i < n; ++i)
	{
		int w, c; cin >> w >> c;

		if (w == 1)
			one.pb(c), cap++;
		else
			two.pb(c), cap += 2;
	}

	sort(one.begin(), one.end());
	sort(two.begin(), two.end());

	vi two_copy = two, one_copy = one;

	int ans_even = 0, ans_odd = 0;

	if (one_copy.size())
		ans_odd = one_copy.back(), one_copy.pop_back();

	cout << ans_odd << ' ';

	for (int i = 2; i <= cap; ++i)
	{
		if (i & 1)
		{
			ans_odd += get_next(one_copy, two_copy);
			cout << ans_odd << ' ';
		}

		else
		{
			ans_even += get_next(one, two);
			cout << ans_even << ' ';
		}

	}

	cout << '\n';
	return 0;
}
