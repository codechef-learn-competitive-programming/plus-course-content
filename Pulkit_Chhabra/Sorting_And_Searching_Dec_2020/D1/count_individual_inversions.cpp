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

//O(Logn) space mein merge sort
// and cnt inversions for all indices
vi cnt;
int mx;

void cntInvAndMerge(vi &arr, int l, int mid, int r)
{
	//old-value -> arr[i]%mx
	//new-value -> arr[i]/mx

	//arr[i] += mx*new_val

	int i = l, j = mid + 1, k = l;

	while (i <= mid and j <= r)
	{
		if (arr[i] % mx <= arr[j] % mx) // compare old values
			arr[k++] += mx * (arr[i++] % mx);

		else
		{
			cnt[j] += mid + 1 - i;
			arr[k++] += mx * (arr[j++] % mx);
		}
	}

	while (j <= r)
		arr[k++] += mx * (arr[j++] % mx);

	while (i <= mid)
		arr[k++] += mx * (arr[i++] % mx);

	for (int i = l; i <= r; ++i)
		arr[i] /= mx;

}

void cntInvAndSort(vi &arr, int l, int r)
{
	if (l >= r) //no. of elements <= 1
		return;

	int mid = (l + r) / 2;

	cntInvAndSort(arr, l, mid); // l to mid
	cntInvAndSort(arr, mid + 1, r); // mid+1 to r
	cntInvAndMerge(arr, l, mid, r);
}

int32_t main()
{
	FIO;
	int n; cin >> n;
	cnt.resize(n);

	vi arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	mx = *(max_element(arr.begin(), arr.end())) + 1;

	cntInvAndSort(arr, 0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	cout << '\n';

	for (int i = 0; i < n; ++i)
		cout << cnt[i] << ' ';
	cout << '\n';

	return 0;
}
