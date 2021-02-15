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

class custom_vec
{
	int *a;
	int sz, cap;
public:
	custom_vec()
	{

		a = NULL, sz = 0, cap = 0;
	}

	void push_back(int num)
	{
		if (sz + 1 <= cap)
		{
			a[sz] = num;
			sz++;
		}

		else
		{
			int *b;

			if (cap)
				b = new int[2 * cap], cap *= 2;
			else
				b = new int[1], cap = 1;

			for (int i = 0; i < sz; ++i)
				b[i] = a[i];

			delete[] a;

			a = b;
			a[sz] = num;
			sz++;
		}
	}

	int size()
	{
		return sz;
	}

	int capacity()
	{
		return cap;
	}

	void pop_back()
	{
		if (sz)
			sz--;
	}

	int & back()
	{
		return a[sz - 1];
	}

	int operator[](int i) {

		if (i >= 0 and i < sz)
			return a[i];

		else
			return -1;
	}
};

int32_t main()
{
	FIO;
	/*int n; cin >> n;

	vi tmp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// v.begin() -> points to the 1st element
	// v.end() -> points to the address just next to the last element
	//(v.end() - 1) -> last element
	//v.end() = v.begin() + n;

	//vi v;
	//vi v(n);
	//vi v(n,5);
	vi v(tmp.begin() + 1, tmp.begin() + 5);

	for (int i : v)
		cout << i << ' ';

	vi v;
	//done some work

	v.resize(n);*/

	vi tmp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	/*tmp.resize(5);

	for (int i : tmp)
		cout << i << ' ';*/

	tmp.assign(12, 1);

	/*for (int i : tmp)
		cout << i << ' ';*/

	cout << tmp.size() << ' ' << tmp.capacity() << '\n';
	tmp.pb(5);
	cout << tmp.size() << ' ' << tmp.capacity() << '\n';

	//tmp.insert(tmp.begin(),1) // O(n)

	return 0;
}
