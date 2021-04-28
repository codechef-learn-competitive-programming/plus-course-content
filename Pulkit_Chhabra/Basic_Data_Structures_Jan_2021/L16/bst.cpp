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

class node {
public:
	node *left, *right;
	int val, freq;

	node(int d)
	{
		left = right = NULL;
		val = d;
		freq = 1;
	}
};

class custom_multiset {
	node *root;
	int sz;

	node *find_aux(node *cur, int val)
	{
		if (cur == NULL or cur->val == val)
			return cur;

		if (cur->val < val)
			return find_aux(cur->right, val);

		return find_aux(cur->left, val);
	}

	node* insert_aux(node *cur, int val)
	{
		if (!cur)
		{
			node *tmp = new node(val);
			return tmp;
		}

		if (cur->val == val)
		{
			cur->freq++;
			return cur;
		}

		if (cur->val < val)
			cur->right = insert_aux(cur->right, val);

		else
			cur->left = insert_aux(cur->left, val);

		return cur;
	}

	node* erase_aux(node *cur, int val)
	{
		if (cur->val < val)
		{
			cur->right = erase_aux(cur->right, val);
			return cur;
		}

		if (cur->val > val)
		{
			cur->left = erase_aux(cur->left, val);
			return cur;
		}

		if (cur->freq > 1)
		{
			cur->freq--;
			return cur;
		}

		// cur ko hi erase karna h
		if (!(cur->right))
		{
			node *tmp = cur->left;
			delete cur;
			return tmp;
		}

		if (!(cur->left))
		{
			node *tmp = cur->right;
			delete cur;
			return tmp;
		}

		node *tmp = cur->left, *prev = cur;

		while (tmp->right)
			prev = tmp, tmp = tmp->right;

		// tmp -> largest in left
		// prev -> parent of tmp

		if (prev != cur)
			prev->right = NULL;
		else
			prev->left = tmp->left;

		cur->val = tmp->val, cur->freq = tmp->freq;
		delete tmp;

		return cur;
	}

public:
	custom_multiset()
	{
		sz = 0;
	}

	custom_multiset(vector<int> v)
	{
		for (int i : v)
			insert(i);
	}

	node *find(int val)
	{
		return find_aux(root, val);
	}

	void insert(int val)
	{
		if (!root)
			root = new node(val);
		else
			insert_aux(root, val);
		sz++;
	}

	void erase(int val)
	{
		if (!find(val))
			return;

		if (sz > 1)
			erase_aux(root, val);
		else
		{
			delete root;
			root = NULL;
		}

		sz--;
	}

	int size()
	{
		return sz;
	}

	int lower_bound(int val)
	{
		node *cur = root;
		int ans = INT_MAX;

		while (cur)
		{
			if (cur->val >= val)
				ans = cur->val, cur = cur->left;
			else
				cur = cur->right;
		}

		return ans;
	}
};

int32_t main()
{
	FIO;
	custom_multiset s;

	s.insert(5);
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(10);
	s.insert(10);

	cout << s.find(2) << '\n';
	s.erase(2);
	cout << s.find(2) << '\n';

	s.insert(7);
	s.insert(6);
	s.insert(15);

	cout << s.lower_bound(9) << '\n';
	s.erase(10);
	cout << s.lower_bound(9) << '\n';
	s.erase(10);
	cout << s.lower_bound(9) << '\n';
	s.erase(10);
	cout << s.lower_bound(9) << '\n';

	return 0;
}
