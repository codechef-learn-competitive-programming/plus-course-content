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

int32_t main()
{
	FIO;
	int n; cin >> n;
	vi v(n);

	for (int &i : v)
		cin >> i;

	multiset<int> lt, rt(v.begin(), v.end());

	int ans = LLONG_MAX;

	for (int j = 0; j < n; ++j)
	{
		rt.erase(rt.find(v[j]));

		auto it_r = rt.upper_bound(v[j]);
		auto it_l = lt.lower_bound(v[j]); //req_it = it_l - 1;

		if (it_r != rt.end() and it_l != lt.begin())
		{
			it_l--;
			ans = min(ans, v[j] + (*it_r) - (*it_l));
		}

		lt.insert(v[j]);
	}

	cout << ans << '\n';

	return 0;
}
