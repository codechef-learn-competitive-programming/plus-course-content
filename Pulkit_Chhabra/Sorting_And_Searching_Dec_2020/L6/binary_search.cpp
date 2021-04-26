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

int bin_search_rec(int *arr, int beg, int end, int target)
{
	if (beg > end)
		return -1;

	int mid = (beg + end) / 2;

	if (arr[mid] < target)
		return bin_search_rec(arr, mid + 1, end, target);

	if (arr[mid] > target)
		return bin_search_rec(arr, beg, mid - 1, target);

	return mid;
}

int bin_search_iter(int *arr, int n, int target)
{
	int beg = 0, end = n - 1;

	while (beg <= end)
	{
		int mid = (beg + end) / 2;

		if (arr[mid] == target)
			return mid;

		else if (arr[mid] > target)
			end = mid - 1;

		else
			beg = mid + 1;
	}

	return -1;
}

int32_t main()
{
	FIO;
	int n; cin >> n;
	mk(arr, n, int);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int x; cin >> x;

	cout << bin_search_rec(arr, 0, n - 1, x) << '\n';
	cout << bin_search_iter(arr, n, x) << '\n';
	return 0;
}
