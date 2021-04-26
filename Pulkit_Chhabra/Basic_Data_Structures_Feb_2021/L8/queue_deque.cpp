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

class node
{
public:
	int data;
	node* next;
	node(int d) : data(d), next(NULL) {}
};

class custom_queue_ll
{
	node *head, *tail;
	int sz;
public:

	custom_queue_ll() : head(NULL), tail(NULL), sz(0) {}

	void push(int num)
	{
		node *new_node = new node(num);

		if (!sz)
			head = tail = new_node;

		else
			tail->next = new_node, tail = new_node;

		sz++;
	}

	int front()
	{
		if (sz)
			return head->data;

		cout << "Queue Empty!\n";
		return -1;
	}

	int back()
	{
		if (sz)
			return tail->data;

		cout << "Queue Empty!\n";
		return -1;
	}

	void pop()
	{
		if (!sz)
		{
			cout << "Queue Empty!\n";
			return;
		}

		if (sz == 1)
			tail = NULL;

		node *new_head = head->next;
		delete head;

		head = new_head;
		sz--;
	}

	int size()
	{
		return sz;
	}

	bool empty()
	{
		return (sz == 0);
	}

	void clear()
	{
		while (sz)
			pop();
	}
};

class circular_queue_array {
	int *arr, st, en, sz, cap;
public:
	circular_queue_array(int capac)
	{
		arr = new int[capac];
		st = 0, en = -1, sz = 0, cap = capac;
	}

	void push(int num)
	{
		if (sz == cap)
		{
			cout << "Queue Full!\n";
			return;
		}

		en = (en + 1) % cap;
		arr[en] = num;
		sz++;
	}

	int front()
	{
		if (sz)
			return arr[st];

		cout << "Queue Empty!\n";
		return -1;
	}

	int back()
	{
		if (sz)
			return arr[en];

		cout << "Queue Empty!\n";
		return -1;
	}

	void pop()
	{
		if (!sz)
		{
			cout << "Queue Empty!\n";
			return;
		}

		st = (st + 1) % cap;
		sz--;
	}

	int size()
	{
		return sz;
	}

	bool empty()
	{
		return (sz == 0);
	}

	void clear()
	{
		while (sz)
			pop();
	}
};

class circular_deque_array {
	int *arr, st, en, sz, cap;
public:

	circular_deque_array(int capac)
	{
		arr = new int[capac];
		st = 0, en = 0, sz = 0, cap = capac;
	}

	void push_back(int num)
	{
		if (sz == cap)
		{
			cout << "Queue Full!\n";
			return;
		}

		if (sz == 0)
		{
			st = en = 0;
			sz = 1;
			arr[en] = num;
			return;
		}

		en = (en + 1) % cap;
		arr[en] = num;
		sz++;
	}

	void push_front(int num)
	{
		if (sz == cap)
		{
			cout << "Queue Full!\n";
			return;
		}

		if (sz == 0)
		{
			st = en = 0;
			sz = 1;
			arr[st] = num;
			return;
		}

		st = (st - 1 + cap) % cap;
		arr[st] = num;
		sz++;
	}

	int front()
	{
		if (sz)
			return arr[st];

		cout << "Queue Empty!\n";
		return -1;
	}

	int back()
	{
		if (sz)
			return arr[en];

		cout << "Queue Empty!\n";
		return -1;
	}

	void pop_front()
	{
		if (!sz)
		{
			cout << "Queue Empty!\n";
			return;
		}

		st = (st + 1) % cap;
		sz--;
	}

	void pop_back()
	{
		if (!sz)
		{
			cout << "Queue Empty!\n";
			return;
		}

		en = (en - 1 + cap) % cap;
		sz--;
	}

	int size()
	{
		return sz;
	}

	bool empty()
	{
		return (sz == 0);
	}

	void clear()
	{
		while (sz)
			pop_front();
	}
};

int32_t main()
{
	FIO;
	circular_queue_array q(5);

	int n = 5;

	for (int i = 0; i < n; ++i)
		q.push(i);

	q.push(10);
	cout << q.size() << '\n';

	cout << q.front() << '\n';

	q.pop();
	cout << q.front() << '\n';

	q.clear();
	cout << q.size() << '\n';
	cout << q.front() << '\n';

	return 0;
}
