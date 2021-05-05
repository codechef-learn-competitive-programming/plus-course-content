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


class NumArray {
	int n, b, sz;
	vector<int> sum, arr, lazy_a, lazy_d; //sum for each block

public:
	NumArray(vector<int>& nums)
	{
		n = nums.size();
		b = sqrt(n);
		sz = (n + b - 1) / b;

		sum.assign(sz, 0);
		lazy_a.assign(sz, 0);
		lazy_d.assign(sz, 0);
		arr = nums;

		for (int i = 0; i < n; ++i)
			sum[i / b] += arr[i];
	}

	void update(int i, int val) // = val -> += val
	{
		sum[i / b] += val;
		arr[i] += val;
	}

	void update(int l, int r, int a, int d)
	{
		int l_block = l / b, end_l = min(l_block * b + b - 1, n - 1);
		int r_block = r / b, start_r = r_block * b;

		for (int i = l; i <= min(r, end_l); ++i)
			update(i, a + (i - l)*d);

		if (l_block != r_block)
		{
			// update elements in R_block
			for (int i = start_r; i <= r; ++i)
				update(i, a + (i - l)*d);

			// update lazy of intermediate blocks
			for (int block = l_block + 1; block < r_block; ++block)
				lazy_a[block] += a + (block * b - l) * d, lazy_d[block] += d;
		}
	}

	int sumRange(int l, int r)
	{
		int ans = 0;

		int l_block = l / b;
		int start_l = l_block * b, end_l = min(l_block * b + b - 1, n - 1);
		int r_block = r / b, start_r = r_block * b;

		// add elements from L_block
		for (int i = l; i <= min(r, end_l); ++i)
			ans += arr[i] + lazy_a[l / b] + lazy_d[l / b] * (i - start_l);

		if (l_block != r_block)
		{
			// add elements from R_block
			for (int i = start_r; i <= r; ++i)
				ans += arr[i] + lazy_a[r / b] + lazy_d[r / b] * (i - start_r);

			// add sum_values of intermediate blocks
			for (int block = l_block + 1; block < r_block; ++block)
				ans += sum[block] + b * lazy_a[block] + lazy_d[block] * b * (b - 1) / 2;
		}

		return ans;
	}
};

int32_t main()
{
	FIO;
	int n, q; cin >> n >> q;
	vi arr(n);

	for (int &i : arr)
		cin >> i;

	NumArray ds(arr);

	while (q--) // 0-based indexing
	{
		int tp; cin >> tp;
		if (tp == 1)
		{
			int l, r, a, d; cin >> l >> r >> a >> d;
			ds.update(l, r, a, d);
		}
		else
		{
			int l, r; cin >> l >> r;
			cout << ds.sumRange(l, r) << '\n';
		}
	}
	return 0;
}
