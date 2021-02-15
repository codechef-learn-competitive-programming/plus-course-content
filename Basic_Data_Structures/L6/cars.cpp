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

int32_t main()
{
	FIO;
	int n; cin >> n;
	stack<int> s1, s2;

	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		s1.push(x);
	}

	int car = 1;

	while (car <= n)
	{
		if (s1.size() and s1.top() == car)
			s1.pop(), car++;

		else if (s2.size() and s2.top() == car)
			s2.pop(), car++;

		else if (s1.size())
			s2.push(s1.top()), s1.pop(); //car ko waiting mein bhej diya

		else
		{
			cout << "Not Possible\n";
			return 0;
		}
	}

	cout << "Possible\n";

	return 0;
}
