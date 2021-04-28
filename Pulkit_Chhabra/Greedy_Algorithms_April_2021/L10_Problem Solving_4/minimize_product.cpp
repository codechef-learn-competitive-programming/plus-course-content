#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define ll             long long
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

bool prime(int n)
{
	for (int i = 2; i * i <= n; ++i)
		if (!(n % i))
			return 0;

	return 1;
}

ll pwmd(ll a, ll n = mod - 2)
{
	if (!n)
		return 1;
	ll pt = pwmd(a, n / 2);
	pt *= pt, pt %= mod;
	if (n & 1)
		pt *= a, pt %= mod;
	return pt;
}

int cnt[20000];

int32_t main()
{
	FIO;

	vi primes = {2};

	for (int n = 3; n <= 10000; n += 2)
	{
		if (prime(n))
			primes.pb(n);
	}

	int prm_sz = primes.size();

	w(t)
	{
		int n; cin >> n;
		vi arr(n);

		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		// > 10^4 vale primes also have to be taken care of
		ll ans = 1;

		for (int prm : primes)
		{
			for (int i = 0; i < n; ++i)
			{
				cnt[i] = 0;
				while ((arr[i] % prm) == 0)
					cnt[i]++, arr[i] /= prm;
			}

			pqb pq;

			for (int i = 0; i < n; ++i)
				if (cnt[i])
					pq.push(cnt[i]);

			while (pq.size() > 1)
			{
				int mx = pq.top();
				pq.pop();
				int scmx = pq.top();
				pq.pop();

				mx--, scmx--;

				if (scmx)
					pq.push(scmx);

				if (mx)
					pq.push(mx);
			}

			if (pq.size() == 1)
			{
				int pow = pq.top();
				ans *= pwmd(prm, pow);
				ans %= mod;
			}

		}

		// Deal with greater primes
		mii cnt;

		for (int i = 0; i < n; ++i)
			if (arr[i] > 1)
				cnt[arr[i]] = 1 - cnt[arr[i]];

		for (auto &p : cnt)
			if (p.ss)
				ans *= p.ff, ans %= mod;

		cout << ans << '\n';
	}
	return 0;
}
