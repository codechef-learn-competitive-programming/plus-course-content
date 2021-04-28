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


// This solution is discussed in the upcoming Doubt Solving Session

int32_t main()
{
	FIO;
	w(t)
	{
		int n, m; cin >> n >> m;
		vector<string> arr(n);

		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		vi enemies(n);
		vector<vi> lasers;

		// Masks for enemies
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (arr[i][j] == 'E')
					enemies[i] += (1ll << j);

				else if (arr[i][j] == 'L')
					lasers.pb({i, j});

		sort(lasers.rbegin(), lasers.rend());

		int l_cnt = lasers.size();
		string ans = "Impossible";

		for (int msk = 0; msk < (1 << l_cnt); ++msk)
		{
			int id = 0, cols_left = (1ll << m) - 1, poss = 1;

			for (int i = n - 1; i >= 0; --i)
			{
				vi horiz, vert;

				while (id < l_cnt and lasers[id][0] == i)
				{
					if ((msk >> id) & 1)
						horiz.pb(lasers[id][1]);
					else
						vert.pb(lasers[id][1]);

					id++;
				}

				int enemies_left = enemies[i] & cols_left;

				if (setbits(enemies_left) >= 1 and horiz.size() <= 1)
				{
					int mn = __builtin_ctzll(enemies_left);
					int mx = 63 - __builtin_clzll(enemies_left);

					if (horiz.empty() or (mn < horiz[0] and mx > horiz[0]))
						poss = 0;
				}

				for (int j : vert)
					cols_left &= (1ll << m) - 1 - (1ll << j);
			}

			if (poss)
			{
				ans = "Possible";
				break;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}
