#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define int 			long long
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void in(vi &v)
{
	for (int &i : v)
		cin >> i;
}

void in2(vector<set<int> > &v, int m)
{
	while (m--)
	{
		int i, j; cin >> i >> j;
		i--, j--;
		v[i].insert(j);
	}
}

vi get(vi a, vi b, vector<set<int> > &cant)
{
	int n1 = a.size(), n2 = b.size();
	vi ans(n1, INT_MAX);

	vector<pii> new_b;

	for (int i = 0; i < n2; ++i)
		new_b.pb({b[i], i});

	sort(new_b.begin(), new_b.end());

	for (int i = 0; i < n1; ++i)
	{
		int j = 0;

		while (j < n2 and cant[i].count(new_b[j].ss))
			j++;

		if (j < n2)
			ans[i] = min(ans[i], a[i] + new_b[j].ff);
	}

	return ans;

}

int32_t main()
{
	FIO;
	int n1, n2, n3, n4; cin >> n1 >> n2 >> n3 >> n4;

	vi a(n1), b(n2), c(n3), d(n4);

	in(a);
	in(b);
	in(c);
	in(d);

	int m1, m2, m3;

	cin >> m1;
	vector<set<int> > ea(n1);
	in2(ea, m1);

	cin >> m2;
	vector<set<int> > eb(n2);
	in2(eb, m2);

	cin >> m3;
	vector<set<int> > ec(n3);
	in2(ec, m3);

	vi c_cost = get(c, d, ec);
	vi b_cost = get(b, c_cost, eb);
	vi a_cost = get(a, b_cost, ea);

	int ans = *min_element(a_cost.begin(), a_cost.end());

	if (ans == INT_MAX)
		cout << -1 << '\n';

	else
		cout << ans << '\n';

	return 0;
}
