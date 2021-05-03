#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// https://cses.fi/problemset/task/1648

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

void update_cost_multi_bfs(vector<vi> &pending, int n, int m, vector<vi> &cost)
{
	queue<vi> q;
	vector<vector<bool> > vis(n + 1, vector<bool>(m + 1));
	vector<vi> dist(n + 1, vi(m + 1, -1));

	for (vi &v : pending)
	{
		q.push(v);
		dist[v[0]][v[1]] = 0;
	}

	int di[] = {0, 0, -1, 1};
	int dj[] = { -1, 1, 0, 0};

	while (!q.empty())
	{
		int i = q.front()[0], j = q.front()[1];
		q.pop();

		for (int id = 0; id < 4; ++id)
		{
			int r = i + di[id], c = j + dj[id];

			if (min(r, c) >= 1 and r <= n and c <= m and dist[r][c] == -1)
				q.push({r, c}), dist[r][c] = dist[i][j] + 1;

		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cost[i][j] = min(cost[i][j], dist[i][j]);
}

int32_t main()
{
	FIO;
	int n, m; cin >> n >> m;
	int q; cin >> q;

	// Initially all-white;
	vector<vi> cost(n + 1, vi(m + 1, inf));

	int b = sqrt(q), cur_b = 0;

	// After answering each query
	// Check if current query if the last query of this block
	vector<vi> pending;

	for (int qry = 0; qry < q; ++qry)
	{
		int i, j; cin >> i >> j;

		int ans = cost[i][j];

		for (auto &v : pending)
			ans = min(ans, abs(i - v[0]) + abs(j - v[1]));

		if (ans == inf)
			ans = -1;

		cout << ans << '\n';

		pending.pb({i, j}); // Make it black

		// Check if 'qry' is the last index in this block
		if (qry == cur_b * b + b - 1)
		{
			update_cost_multi_bfs(pending, n, m, cost);
			pending.clear();
			cur_b++;
		}
	}

	return 0;
}
