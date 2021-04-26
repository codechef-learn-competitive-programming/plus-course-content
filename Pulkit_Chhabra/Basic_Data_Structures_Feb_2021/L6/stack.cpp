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

class custom_stack
{
	int arr[1000];
	int sz = 0;
public:
	void push(int num)
	{
		if (sz == 1000)
		{
			cout << "Stack Full!\n";
			return;
		}


		arr[sz++] = num;
	}

	int top()
	{
		if (sz == 0)
		{
			cout << "Stack Empty!\n";
			return -1;
		}
		return arr[sz - 1];
	}

	void pop()
	{
		if (sz == 0)
		{
			cout << "Stack Empty!\n";
			return;
		}
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
		sz = 0;
	}
};


class custom_stack_vector
{
	vector<int> arr;
public:
	void push(int num)
	{
		arr.push_back(num);
	}

	int top()
	{
		if (arr.empty())
			return -1;

		return arr.back();
	}

	void pop()
	{
		if (arr.empty())
		{
			cout << "Stack Empty!";
			return;
		}
		arr.pop_back();
	}

	int size()
	{
		return arr.size();
	}

	bool empty()
	{
		return arr.empty();
	}

	void clear()
	{
		arr.clear();
	}
};

class node
{
public:
	int data;
	node* next;
	node(int d) : data(d), next(NULL) {}
};

class custom_stack_ll
{
	node *head;
	int sz;
public:

	custom_stack_ll() : head(NULL), sz(0) {}

	void push(int num)
	{
		node *new_head = new node(num);

		new_head->next = head;
		head = new_head;
		sz++;
	}

	int& top()
	{
		if (sz)
			return head->data;

		cout << "Stack Empty!\n";
		return head->data;
	}

	void pop()
	{
		if (!sz)
		{
			cout << "Stack Empty!\n";
			return;
		}

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

class max_min_stack
{
	stack<int> s, mn, mx;
public:
	void push(int num)
	{
		s.push(num);

		mn.empty() ? mn.push(num) : mn.push(std::min(num, mn.top()));
		mx.empty() ? mx.push(num) : mx.push(std::max(num, mx.top()));
	}

	void pop()
	{
		s.pop(), mn.pop(), mx.pop();
	}

	int top()
	{
		return s.top();
	}

	int max()
	{
		return mx.top();
	}

	int min()
	{
		return mn.top();
	}
};

int32_t main()
{
	FIO;
	/*custom_stack_ll s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	s.pop();
	s.push(5);

	s.top()++;

	while (!s.empty())
	{
		cout << s.top() << '\n';
		s.pop();
	}
	*/

	max_min_stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(-1);

	cout << s.max() << ' ' << s.min() << '\n';

	s.pop();
	cout << s.max() << ' ' << s.min() << '\n';

	return 0;
}
