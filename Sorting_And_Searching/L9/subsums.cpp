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

vi get_subset_sums(vi arr)
{
	int n = arr.size();

	vi ans;

	for (int mask = 0; mask < (1 << n); ++mask)
	{
		int sum_in_this_case = 0;

		for (int i = 0; i < n; ++i)
			if (mask & (1 << i))
				sum_in_this_case += arr[i];

		ans.pb(sum_in_this_case);
	}

	return ans;
}

int32_t main()
{
	FIO;
	int n, a, b; cin >> n >> a >> b;

	vi v(n);

	for (int &i : v)
		cin >> i;

	vi left(v.begin(), v.begin() + n / 2); //[0, n/2)
	vi right(v.begin() + n / 2, v.end()); //[n/2, n)

	vi l = get_subset_sums(left), r = get_subset_sums(right);

	sort(r.begin(), r.end());
	int ans = 0;

	for (int l_sum : l)
	{
		auto ub = upper_bound(r.begin(), r.end(), b - l_sum);
		auto lb = lower_bound(r.begin(), r.end(), a - l_sum);

		int num_of_valid_values = ub - lb;

		ans += num_of_valid_values;
	}

	cout << ans << '\n';
	return 0;
}
