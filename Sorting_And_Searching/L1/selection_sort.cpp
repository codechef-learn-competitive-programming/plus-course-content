#include<bits/stdc++.h>
using namespace std;

void selection_sort(int *arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min_id = i;

		for (int j = i + 1; j < n; ++j)
			if (arr[j] < arr[min_id])
				min_id = j;

		swap(arr[min_id], arr[i]);
	}
}

int main()
{
	int n; cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	selection_sort(arr, n);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
}
