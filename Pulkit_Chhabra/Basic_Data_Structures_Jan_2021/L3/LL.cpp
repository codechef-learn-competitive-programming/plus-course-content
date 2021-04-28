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
	int data;
	node *next;
	node *prev;

	node(int d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}
};

class LinkedList {
public:
	node *head;
	node *tail;
	int size;

	LinkedList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void push_front(int d)
	{
		node *new_head = new node(d);

		if (head == NULL)
			tail = new_head, head = new_head;

		else
		{
			new_head -> next = head;
			head -> prev = new_head;
			head = new_head;
		}

		size++;
	}

	void push_back(int d)
	{
		node *new_tail = new node(d);

		if (tail == NULL)
			head = new_tail, tail = new_tail;

		else
		{
			tail->next = new_tail;
			new_tail->prev = tail;
			tail = new_tail;
		}

		size++;
	}

	node* insert(node *cur, int d) //insert just after the cur node
	{
		node *new_node = new node(d);

		new_node->next = cur->next;
		cur->next = new_node;

		new_node -> prev = cur;

		if (new_node->next)
			new_node->next->prev = new_node;

		else
			tail = new_node;

		size++;

		return new_node;
	}

	void pop_back()
	{
		if (!tail)
			return;

		if (!(tail->prev))
		{
			delete tail;
			head = tail = NULL;
		}

		else
		{
			node *new_tail = tail->prev;

			new_tail->next = NULL;
			delete tail;

			tail = new_tail;
		}

		size--;
	}

	void pop_front()
	{
		if (!head)
			return;

		if (!(head->next))
		{
			delete head;
			head = tail = NULL;
		}

		else
		{
			node *new_head = head->next;

			delete head;
			new_head->prev = NULL;

			head = new_head;
		}
		size--;
	}

	void pop(node* cur) //Delete this node
	{
		if (size == 1)
		{
			delete cur;
			head = tail = NULL;
		}

		//prev->next = next, next->prev = cprev

		if (cur->prev)
			cur->prev->next = cur->next;

		if (cur->next)
			cur->next->prev = cur->prev;

		if (cur == head)
			head = cur->next;

		if (cur == tail)
			tail = cur->prev;

		delete cur;
		size--;
	}

	void print_iter()
	{
		node *cur = head;

		while (cur)
		{
			cout << cur->data << ' ';
			cur = cur->next;
		}

		cout << '\n';
	}

	void print_rec_aux(node *cur)
	{
		if (!cur)
			return;

		cout << cur->data << ' ';
		print_rec_aux(cur->next);
	}

	void print_rec()
	{
		print_rec_aux(head);
		cout << '\n';
	}

	void reverse()
	{
		node *cur = head;

		while (cur)
		{
			//node *old_next = cur->next;
			swap(cur->next, cur->prev);
			//cur = old_next;
			cur = cur->prev;
		}

		swap(head, tail);
	}

	void reverse_singly()
	{
		node *cur = head, *prev = NULL;

		while (cur)
		{
			node *next_node = cur->next;

			cur->next = prev;

			prev = cur;
			cur = next_node;
		}

		swap(head, tail);
	}
};

int32_t main()
{
	FIO;
	LinkedList l;

	for (int i = 1; i <= 10; ++i)
		l.pb(i);

	l.print_iter();

	l.pop_back();
	l.print_iter();

	l.pop_front();
	l.print_iter();

	node *eleven = l.insert(l.head, 11);
	l.print_iter();

	cout << l.size << '\n';

	l.pop(eleven);
	l.print_iter();

	l.pop(l.head);
	l.print_iter();

	l.pop(l.tail);
	l.print_iter();

	l.reverse();
	l.print_iter();

	l.reverse_singly();
	l.print_iter();

	return 0;
}
