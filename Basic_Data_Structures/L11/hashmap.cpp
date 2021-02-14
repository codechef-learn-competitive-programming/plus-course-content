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

class mapsi {
	vector< list<pair<string, int> > > v;
	int n, sz;
	double lf, mx_lf;

	int hash(string s)
	{
		int p = 257, ans = 0, ln = s.size();

		for (int i = ln - 1; i >= 0; --i)
		{
			int cur = (int)s[i];
			ans = (ans * p + cur) % n;
		}

		return ans;
	}

	void rehash()
	{
		vector< list<pair<string, int> > > v2(2 * n);

		n = 2 * n;
		for (int i = 0; i < n / 2; ++i)
			for (auto p : v[i])
				v2[hash(p.ff)].pb(p);

		v = v2;
		lf = sz / (double)n;
	}

public:
	mapsi()
	{
		v.resize(1);
		n = 1, sz = 0;
		lf = 0.0;
		mx_lf = 1.0;
	}

	void erase(string s)
	{
		int id = hash(s);

		for (auto it = v[id].begin(); it != v[id].end(); ++it)
			if (it->ff == s)
			{
				v[id].erase(it);
				sz--;
				return;
			}
	}

	int &operator[](string s)
	{
		int id = hash(s);

		for (auto &p : v[id])
			if (p.ff == s)
				return p.ss;

		v[id].pb({s, 0});
		sz++;
		lf = sz / (double)n;

		if (lf <= mx_lf)
			return v[id].back().ss;

		rehash();
		return find(s)->ss;
	}

	list<pair<string, int> >::iterator find(string s)
	{
		int id = hash(s);

		for (auto it = v[id].begin(); it != v[id].end(); ++it)
			if (it->ff == s)
				return it;

		return v.back().end();
	}

	int count(string s)
	{
		int id = hash(s);

		for (auto it = v[id].begin(); it != v[id].end(); ++it)
			if (it->ff == s)
				return 1;

		return 0;
	}

	int size()
	{
		return sz;
	}

	int bucket_count()
	{
		return n;
	}

	void insert(pair<string, int> p)
	{
		string s = p.ff;
		int val = p.ss;
		int id = hash(s);

		for (auto &p : v[id])
			if (p.ff == s)
			{
				p.ss = val;
				return;
			}

		v[id].pb({s, val});
		sz++;
		lf = sz / (double)n;

		if (lf > mx_lf)
			rehash();
	}

};

struct hash_pair {

	size_t operator()(pair<int, int> p)
	{
		return p.ff * 100000000 + p.ss;
	}
};


int32_t main()
{
	FIO;
	/*mapsi m;

	int n = 10;

	for (int i = 1; i <= n; ++i)
	{
		string s;
		s += (char)('a' + i);
		m[s] = i;

		//cout << m.size() << ' ' << m.bucket_count() << '\n';
	}

	cout << m["d"] << '\n';
	cout << m.count("d") << '\n';

	m.erase("d");

	cout << m.count("d") << '\n';
	cout << m["d"] << '\n';
	cout << m.count("d") << '\n';*/

	unordered_map<pair<string, string> , int> m;

	/*m.insert({1, 1});

	m[5] = 2;

	cout << m[10] << '\n';

	if (m.count(10))
		cout << "10 present\n";

	auto it = m.find(10);

	if (it != m.end())
		it->ss = 10;

	cout << m[10] << '\n';*/
	//m.max_load_factor(0.25);
	//m.reserve(1024);

	//cout << m.bucket_count() << '\n';
	return 0;
}
