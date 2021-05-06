#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// https://cses.fi/problemset/task/1735/

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
	vector<int> sum, arr, lazyAdd, lazyAssign;

public:
	NumArray(vector<int>& nums)
	{
		n = nums.size();
		b = sqrt(n);

		sz = (n + b - 1) / b;

		sum.assign(sz, 0);
		lazyAdd.assign(sz, 0);
		lazyAssign.assign(sz, 0);
		arr = nums;

		for (int i = 0; i < n; ++i)
			sum[i / b] += arr[i];
	}

	void ResetAdd(int i, int val, int l, int r)
	{
		int s = i * b, e = min(n - 1, i * b + b - 1), ans = 0;
		for (int id = s; id <= e; ++id)
		{
			if (lazyAssign[i])
				arr[id] = lazyAssign[i] + lazyAdd[i];

			else
				arr[id] += lazyAdd[i];

			if (id >= l and id <= r)
				arr[id] += val;

			ans += arr[id];
		}

		lazyAdd[i] = lazyAssign[i] = 0;
		sum[i] = ans;
	}

	void updateAdd(int l, int r, int val)
	{
		int l_block = l / b, end_l = min(l_block * b + b - 1, n - 1);
		int r_block = r / b, start_r = r_block * b;

		ResetAdd(l / b, val, l, r);

		if (l_block != r_block)
		{
			// update elements in R_block
			ResetAdd(r / b, val, l, r);

			// update lazy of intermediate blocks
			for (int block = l_block + 1; block < r_block; ++block)
				sum[block] += val * b, lazyAdd[block] += val;
		}
	}

	void ResetEquate(int i, int val, int l, int r)
	{
		int s = i * b, e = min(n - 1, i * b + b - 1), ans = 0;
		for (int id = s; id <= e; ++id)
		{
			if (id >= l and id <= r)
				arr[id] = val;

			else if (lazyAssign[i])
				arr[id] = lazyAssign[i] + lazyAdd[i];

			else
				arr[id] += lazyAdd[i];

			ans += arr[id];
		}

		lazyAdd[i] = lazyAssign[i] = 0;
		sum[i] = ans;
	}

	void updateEquate(int l, int r, int val)
	{
		int l_block = l / b, end_l = min(l_block * b + b - 1, n - 1);
		int r_block = r / b, start_r = r_block * b;

		ResetEquate(l / b, val, l, r);

		if (l_block != r_block)
		{
			// update elements in R_block
			ResetEquate(r / b, val, l, r);

			// update lazy of intermediate blocks
			for (int block = l_block + 1; block < r_block; ++block)
				sum[block] = val * b, lazyAssign[block] = val, lazyAdd[block] = 0;
		}
	}

	int sumRange(int l, int r)
	{
		int ans = 0;

		int l_block = l / b, end_l = min(l_block * b + b - 1, n - 1);
		int r_block = r / b, start_r = r_block * b;

		// add elements from L_block
		for (int i = l; i <= min(r, end_l); ++i)
			ans += lazyAssign[l / b] ? lazyAssign[l / b] + lazyAdd[l / b] : arr[i] + lazyAdd[l / b];

		if (l_block != r_block)
		{
			// add elements from R_block
			for (int i = start_r; i <= r; ++i)
				ans += lazyAssign[r / b] ? lazyAssign[r / b] + lazyAdd[r / b] : arr[i] + lazyAdd[r / b];

			// add sum_values of intermediate blocks
			for (int block = l_block + 1; block < r_block; ++block)
				ans += sum[block];
		}

		return ans;
	}
};

int32_t main()
{
	FIO;
	int n, q; cin >> n >> q;
	vi arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	NumArray do_work(arr);

	while (q--)
	{
		int tp, l, r, x; cin >> tp;

		if (tp == 3)
		{
			cin >> l >> r; l--, r--;
			cout << do_work.sumRange(l, r) << '\n';
		}

		else
		{
			cin >> l >> r >> x; l--, r--;

			if (tp == 1)
				do_work.updateAdd(l, r, x);
			else
				do_work.updateEquate(l, r, x);
		}
	}
	return 0;
}
