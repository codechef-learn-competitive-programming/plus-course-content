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

int partition(vi &arr, int l, int r)
{
	int id = rng() % (r - l + 1) + l;
	swap(arr[r], arr[id]);

	int i = l;

	for (int j = l; j <= r; ++j)
		if (arr[j] <= arr[r])
			swap(arr[i], arr[j]), i++;

	return i - 1;
}

int quick_select(vi &arr, int l, int r, int k)
{
	if (l > r)
		return -1;

	int p_i = partition(arr, l, r);

	if (p_i == k - 1)
		return arr[p_i];

	if (p_i > k - 1)
		return quick_select(arr, l, p_i - 1, k);

	return quick_select(arr, p_i + 1, r, k);
}

int32_t main()
{
	FIO;

	w(t)
	{
		int n, k; cin >> n;
		vi arr(n);

		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		cin >> k;

		cout << quick_select(arr, 0, n - 1, k) << '\n';
	}

	return 0;
}
