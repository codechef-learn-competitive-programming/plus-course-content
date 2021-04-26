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


void evaluate(stack<int> &s, char ch)
{
	int b = s.top(); // a operator b
	s.pop();
	int a = s.top();
	s.pop();

	switch (ch)
	{
	case '+' :
		s.push(a + b);
		break;

	case '-' :
		s.push(a - b);
		break;

	case '*' :
		s.push(a * b);
		break;

	case '/' :
		s.push(a / b);
		break;
	}
}

int32_t main()
{
	FIO;

	string s; cin >> s; // valid post-fix exp

	stack<int> operands;

	for (char ch : s)
	{
		if (isdigit(ch))
			operands.push(ch - '0');

		else
			evaluate(operands, ch);
	}

	cout << operands.top() << '\n';

	return 0;
}
