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

class minHeap
{
	vector<int> v;
	int n;

	void siftUp(int i)
	{
		while (i > 1 and v[i / 2] > v[i]) //parent > cur
			swap(v[i / 2], v[i]), i /= 2;
	}

	void siftDown(int i)
	{
		while (i <= n / 2)
		{
			int min_id = i;

			if (v[2 * i] < v[min_id])
				min_id = 2 * i;

			if (2 * i + 1 <= n and v[2 * i + 1] < v[min_id])
				min_id = 2 * i + 1;

			if (min_id != i)
				swap(v[i], v[min_id]), i = min_id;
			else
				break;
		}
	}

	void build()
	{
		for (int i = n / 2; i >= 1; --i)
			siftDown(i);
	}

public:
	minHeap()
	{
		v.pb(0); //iske baad jo bhi aaye, voh 1 mein aaye
		n = 0;
	}

	minHeap(vector<int> arr)
	{
		v.pb(0);
		for (int i : arr)
			v.pb(i);

		n = arr.size();
		build();
	}

	int top()
	{
		return v[1];
	}

	void push(int num)
	{
		v.push_back(num);
		n++;
		siftUp(n);
	}

	int size()
	{
		return n;
	}

	void pop()
	{
		swap(v[1], v[n]); //root sent to last
		v.pop_back();
		n--;

		siftDown(1);
	}

};

int32_t main()
{
	FIO;
	minHeap m(vi{5, 5, 10, 1, 7});

	cout << m.top() << '\n';
	m.pop();
	cout << m.top() << '\n';
	m.pop();
	cout << m.top() << '\n';
	m.pop();
	cout << m.top() << '\n';
	m.pop();
	return 0;
}
