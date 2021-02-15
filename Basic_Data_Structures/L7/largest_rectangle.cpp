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
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


vi prev_smaller(vi arr)
{
	int n = arr.size();
	vi ps(n);

	stack<int> s; // indices

	for (int i = 0; i < n; ++i)
	{
		while (!s.empty() and arr[s.top()] >= arr[i]) // prev smaller
			s.pop();

		s.empty() ? ps[i] = -1 : ps[i] = s.top();

		s.push(i);
	}

	return ps;
}

vi next_smaller(vi arr)
{
	int n = arr.size();
	vi ns(n);

	stack<int> s; // indices

	for (int i = n - 1; i >= 0; --i)
	{
		while (!s.empty() and arr[s.top()] >= arr[i]) // next smaller
			s.pop();

		s.empty() ? ns[i] = n : ns[i] = s.top();

		s.push(i);
	}

	return ns;
}

int32_t main()
{
	FIO;
	int n; cin >> n;
	vi arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	vi ps = prev_smaller(arr), ns = next_smaller(arr);

	int max_area = 0;

	for (int i = 0; i < n; ++i)
	{
		int b = ns[i] - ps[i] - 1;
		int l = arr[i];

		max_area = max(l * b, max_area);
	}

	cout << max_area << '\n';
	return 0;
}
