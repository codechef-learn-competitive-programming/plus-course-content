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

const int b = 300;

class query
{
public:
	int l, r, i, ex;
	query(int lt = 0, int rt = 0, int id = 0, int extra = 0)
	{
		l = lt;
		r = rt;
		i = id;
		ex = extra;
	}

	// func will true when 'this' < q2;
	bool operator <(const query &q2)
	{
		return (l / b < q2.l / b) or
		       (l / b == q2.l / b and
		        ((l / b & 1) ? r < q2.r : r > q2.r));
	}
};

int n, q, timer, distinct;
vi adj[40001];
int arr[40001], node[80000], freq[40001], up[40001][18], in[40001], out[40001], inc[40001];
mii compress;
query queries[100000];
int ans[100000];

bool is_ancestor(int u, int v)
{
	return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v)
{
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;

	for (int i = 17; i >= 0; --i)
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];

	return up[u][0];
} // n*logn

void dfs(int cur = 1, int par = 1)
{
	in[cur] = timer;
	node[timer] = cur;
	timer++;

	//this is for LCA
	up[cur][0] = par;

	for (int nb : adj[cur])
	{
		if (nb == par)
			continue;
		dfs(nb, cur);
	}

	out[cur] = timer;
	node[timer] = cur;
	timer++;
}

void add(int val)
{
	freq[val]++;

	if (freq[val] == 1)
		distinct++;
}

void remove(int val)
{
	freq[val]--;

	if (freq[val] == 0)
		distinct--;
}

void do_the_work(int i)
{
	i = node[i];

	if (inc[i])
		remove(arr[i]);
	else
		add(arr[i]);

	inc[i] = 1 - inc[i];
}
int32_t main()
{
	FIO;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		compress[arr[i]] = 1;
	}

	// Compress the values
	int cur = 1;
	for (auto &p : compress)
		p.ss = (cur++);

	//Re-assign the values
	for (int i = 1; i <= n; ++i)
		arr[i] = compress[arr[i]];

	for (int i = 1; i < n; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	// Pre-processing part
	dfs();

	//For LCA
	for (int j = 1; j < 18; ++j)
		for (int i = 1; i <= n; ++i)
			up[i][j] = up[up[i][j - 1]][j - 1];

	// Let's deal with the queries
	for (int i = 0; i < q; ++i)
	{
		int u, v; cin >> u >> v;

		if (in[u] > in[v])
			swap(u, v);

		int lc = lca(u, v);

		if (lc == u)
			queries[i] = query(in[u], in[v], i);

		else // extra also to be stored
			queries[i] = query(out[u], in[v], i, arr[lc]);
	}

	sort(queries, queries + q);

	int l = 0, r = -1;
	for (int i = 0; i < q; ++i)
	{
		auto &qr = queries[i];

		while (l > qr.l)
			do_the_work(--l);
		while (r < qr.r)
			do_the_work(++r);
		while (l < qr.l)
			do_the_work(l++);
		while (r > qr.r)
			do_the_work(r--);

		ans[qr.i] = distinct;

		//Take care of the extra value
		if (qr.ex and freq[qr.ex] == 0)
			ans[qr.i]++;
	}

	for (int i = 0; i < q; ++i)
		cout << ans[i] << '\n';

	return 0;
}
