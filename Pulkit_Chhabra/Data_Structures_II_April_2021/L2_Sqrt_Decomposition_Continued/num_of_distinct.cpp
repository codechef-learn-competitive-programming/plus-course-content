#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
//#define int             long long
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

int n, b, sz;
vector<vi> part;
vi arr, nxt, prv;
map<int, set<int> > indices;

// https://www.spoj.com/problems/DQUERY/ (Without Updates)

void updateNxt(int id, int val) // 0-based
{
	int i = id / b;

	for (int j = 0; j < part[i].size(); ++j)
		if (part[i][j] == nxt[id])
		{
			nxt[id] = val;
			part[i][j] = val;
			break;
		}

	sort(part[i].begin(), part[i].end());
}

int get_greater(int l, int r) // 0-based
{
	int ans = 0;

	for (int i = l; i < min({n, (l / b + 1)*b, r + 1}); ++i)
		if (nxt[i] > r)
			ans++;

	if (r / b == l / b)
		return ans;

	for (int i = (r / b) * b; i <= r; ++i)
		if (nxt[i] > r)
			ans++;

	for (int i = l / b + 1; i < r / b; ++i)
		ans += part[i].end() - upper_bound(part[i].begin(), part[i].end(), r);

	return ans;
}

int32_t main()
{
	FIO;
	cin >> n;
	b = sqrt(n), sz = (n + b - 1) / b;

	arr.resize(n);
	nxt.resize(n);
	prv.resize(n);
	part.resize(sz);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		indices[arr[i]].insert(i);
	}

	for (int i = 0; i < n; ++i)
	{
		auto it = indices[arr[i]].upper_bound(i);

		nxt[i] = (it == indices[arr[i]].end()) ? n : (*it);

		it--; // it is pointing to 'i' now
		prv[i] = (it == indices[arr[i]].begin()) ? - 1 : *(--it);
	}

	// Initialize Sqrt Decomposition on nxt array
	for (int i = 0; i < n; ++i)
		part[i / b].pb(nxt[i]);

	for (int i = 0; i < sz; ++i)
		sort(part[i].begin(), part[i].end());

	w(q)
	{
		int tp; cin >> tp;

		if (tp == 0)
		{
			int l, r; cin >> l >> r;
			l--, r--;
			cout << get_greater(l, r) << '\n';
		}

		else
		{
			int id, val; cin >> id >> val;
			id--;

			// Update old links
			if (nxt[id] != n)
				prv[nxt[id]] = prv[id];

			if (prv[id] != -1)
				updateNxt(prv[id], nxt[id]);

			indices[arr[id]].erase(id);

			// Update new links
			auto it = indices[val].upper_bound(id);

			int nxt_id = (it == indices[val].end()) ? n : (*it);
			int prv_id = (it == indices[val].begin()) ? -1 : *(--it);

			if (nxt_id != n)
				prv[nxt_id] = id;

			if (prv_id != -1)
				updateNxt(prv_id, id);

			prv[id] = prv_id;
			updateNxt(id, nxt_id);
			indices[val].insert(id);

		}
	}

	return 0;
}
