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

void quick_sort(vi &arr, int l, int r)
{
	if (l >= r)
		return;

	int p_i = partition(arr, l, r);
	quick_sort(arr, l, p_i - 1);
	quick_sort(arr, p_i + 1, r);
}

int32_t main()
{
	FIO;

	int n; cin >> n;
	vi arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
	return 0;
}
