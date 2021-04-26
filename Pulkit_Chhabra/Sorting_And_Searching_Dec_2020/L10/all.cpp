
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
#define ld				long double
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ld f(ld x)
{
	return x * x;
}

int f(int x)
{
	return x * x;
}

ld find_min()
{
	ld l = -1e9, r = 1e9;

	while (r - l > 1e-3)
	{
		ld m1 = l + (r - l) / 3.0;
		ld m2 = r - (r - l) / 3.0;

		if (f(m1) >= f(m2)) //[l,m1) can be discarded
			l = m1;

		else
			r = m2;
	}

	return l;
}

int find_min_discrete()
{
	int l = -1e9, r = 1e9;

	while (r - l >= 3) //no. of elements is search space are >= 4
	{
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;

		if (f(m1) >= f(m2))
			l = m1;

		else
			r = m2;
	}

	int min_val = inf;
	for (int i = l; i <= r; ++i)
		min_val = min(min_val, f(i));

	return min_val;
}


ld f(ld t, vi &s, vi &d)
{
	int n = s.size();

	vector<ld> pos(n);

	for (int i = 0; i < n; ++i)
		pos[i] = s[i] * t + d[i];

	return (*max_element(pos.begin(), pos.end())) - (*min_element(pos.begin(), pos.end()));
}

int32_t main()
{
	FIO;
	int n, k; cin >> n >> k;

	vi s(n), d(n);

	for (int i = 0; i < n; ++i)
		cin >> s[i] >> d[i];

	ld beg = 0.0, end = k, prec = 1e-10; //f(t) -> range for optimal t

	while (end - beg > prec)
	{
		ld m1 = beg + (end - beg) / 3.0;
		ld m2 = end - (end - beg) / 3.0;

		if (f(m1, s, d) < f(m2, s, d)) //(m2,r] can be discarded
			end = m2;

		else
			beg = m1;
	}

	cout << ps(f(beg, s, d), 6) << '\n';

	return 0;
}
