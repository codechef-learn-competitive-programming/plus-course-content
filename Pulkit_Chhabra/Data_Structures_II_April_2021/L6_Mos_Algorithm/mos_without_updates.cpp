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
 
int arr[200000];
const int b = 450;
 
int sum = 0;
 
void add(int id)
{
	sum += arr[id];
}
 
void remove(int id)
{
	sum -= arr[id];
}
 
class query
{
public:
	int l,  r,  i;
	query(int lt = 0, int rt = 0, int id = 0)
	{
		l = lt - 1; // 1 to 0
		r = rt - 1; // 1 to 0
		i = id;
	}
 
	// func will true when 'this' < q2;
	bool operator <(const query &q2)
	{
		return (l / b < q2.l / b) or
		       (l / b == q2.l / b and
		        ((l / b & 1) ? r < q2.r : r > q2.r));
	}
};
 
int32_t main()
{
	FIO;
	int n, q; cin >> n >> q;
 
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
 
	vector<query> queries(q);
 
	for (int i = 0; i < q; ++i)
	{
		int l, r; cin >> l >> r;
		queries[i] = query(l, r, i);
	}
 
	sort(queries.begin(), queries.end());
 
	vi ans(q);
 
	int l = 0, r = -1;
 
	for (query &q : queries)
	{
		while (l > q.l)
			add(--l);
		while (r < q.r)
			add(++r);
		while (l < q.l)
			remove(l++);
		while (r > q.r)
			remove(r--);
 
		ans[q.i] = sum;
	}
 
	for (int i : ans)
		cout << i << '\n';
	return 0;
}
