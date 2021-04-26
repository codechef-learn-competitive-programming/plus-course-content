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


int count_searchable(vi arr)
{
	int n = arr.size();

	vi pre_max(n), suf_min(n);

	pre_max[0] = arr[0];

	for (int i = 1; i < n; ++i)
		pre_max[i] = max(pre_max[i - 1], arr[i]);

	suf_min[n - 1] = arr[n - 1];

	for (int i = n - 2; i >= 0; --i)
		suf_min[i] = min(suf_min[i + 1], arr[i]);

	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == pre_max[i] and arr[i] == suf_min[i])
			ans++;
	}

	return ans;
}

int lb(vi arr, int target) //smallest id s.t. a[id] >= target;
{
	int n = arr.size();

	int beg = 0, end = n - 1, ans = n;

	while (beg <= end)
	{
		int mid = (beg + end) / 2;

		if (arr[mid] >= target)
			ans = mid, end = mid - 1; //search in left

		else // < target
			beg = mid + 1;
	}

	return ans;
}

int ub(vi arr, int target) //smallest id s.t. a[id] >= target;
{
	int n = arr.size();

	int beg = 0, end = n - 1, ans = n;

	while (beg <= end)
	{
		int mid = (beg + end) / 2;

		if (arr[mid] > target)
			ans = mid, end = mid - 1; //search in left

		else // < target
			beg = mid + 1;
	}

	return ans;
}

bool cmp(int a, int b)
{
	return a > b;
}
//should return true if a is before b in sorted order

int32_t main()
{
	FIO;
	vi arr = {1, 2, 2, 5, 6, 7, 10, 11};

	//cout << binary_search(arr.begin(), arr.end(), 5) << '\n';

	auto id = lower_bound(arr.begin(), arr.end(), 5) - arr.begin();
	//cout << id << '\n';

	auto it = lower_bound(arr.begin(), arr.end(), 12); //no element >= 12
	//cout << (it == arr.end()) << '\n';

	vi arr2 = {11, 10, 7, 6, 5, 2, 2, 1, 0};

	cout << binary_search(arr2.begin(), arr2.end(), 4, cmp) << '\n';
	return 0;
}
