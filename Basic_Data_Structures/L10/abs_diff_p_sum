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

pii getAns(vi x, vi p, int n)
{
	int max_diff = p[0] - x[0], max_id = 0, max_ans = INT_MIN;

	pii ans = { -1, -1};

	for (int j = 1; j < n; ++j)
	{
		int cur_sum = p[j] + x[j];

		if (cur_sum + max_diff > max_ans)
			max_ans = cur_sum + max_diff, ans = {max_id, j};

		if (p[j] - x[j] > max_diff)
			max_diff = p[j] - x[j], max_id = j;
	}

	return ans;

}

pii getAns2(vi x, vi p, int n, int k)
{
	pii ans = { -1, -1};
	deque<int> q;
	int max_ans = INT_MIN;

	for (int j = 0; j < n; ++j)
	{
		while (q.size() and x[j] - x[q.front()] > k)
			q.pop_front();

		if (q.size())
		{
			int id = q.front();
			int cur_sum = p[j] + x[j];

			if (cur_sum + p[id] - x[id] > max_ans)
				max_ans = cur_sum + p[id] - x[id], ans = {id, j};
		}

		while (q.size() and p[q.back()] - x[q.back()] <= p[j] - x[j])
			q.pop_back();

		q.push_back(j);
	}

	return ans;
}

pii getAns3(vi x, vi p, int n)
{
	pii ans1 = getAns2(x, p, n, 180);

	pii ans2 = { -1, -1};

	int max_sum = INT_MIN, max_id = -1, i = -1, max_ans = INT_MIN;

	for (int j = 1; j < n; ++j)
	{
		while (i + 1 < j and x[j] - x[i + 1] > 180)
		{
			if (x[i + 1] + p[i + 1] > max_sum)
				max_sum = x[i + 1] + p[i + 1], max_id = i;

			i++;
		}

		int cur_diff = p[j] - x[j];

		if (max_id != -1 and cur_diff + max_sum > max_ans)
			max_ans = cur_diff + max_sum, ans2 = {max_id, j};

	}

	int i = ans1.ff, j = ans1.ss;

	if (i == -1 and max_ans > abs(x[i] - x[j]) + p[i] + p[j])
		return ans2;

	return ans1;
}

int32_t main()
{
	FIO;
	int n; cin >> n;
	vi x(n), p(n);

	for (int &i : x)
		cin >> i;

	for (int &i : p)
		cin >> i;


	return 0;
}
