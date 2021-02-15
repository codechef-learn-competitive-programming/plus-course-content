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

int prec(char ch)
{
	if (ch == '/' or ch == '*')
		return 2;

	if (ch == '+' or ch == '-')
		return 1;

	return -1;
}

int32_t main()
{
	FIO;
	string s; cin >> s; // in-fix -> {(), +, -, *, /, alphabets}

	stack<char> operators;
	string ans;

	for (char ch : s)
	{
		if (isalpha(ch))
			ans += ch;

		else if (ch == '(')
			operators.push(ch);

		else if (ch == ')')
		{
			while (operators.top() != '(')
				ans += operators.top(), operators.pop();

			operators.pop();
		}

		else
		{
			while (operators.size() and prec(operators.top()) >= prec(ch))
				ans += operators.top(), operators.pop();

			operators.push(ch);
		}
	}

	while (!operators.empty())
		ans += operators.top(), operators.pop();

	cout << ans << '\n';

	return 0;
}
