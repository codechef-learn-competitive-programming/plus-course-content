#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr, int n)
{
	//[0..0] is sorted
	//[a[1] -> 0..0]
	//[a[2] -> 0..1]
	//[a[3] -> 0..2]
	//...
	//a[n-1] -> [0...n-2]

	for (int i = 1; i <= n - 1; ++i)
	{
		int x = arr[i];

		//what all numbers should be shifted
		int j = i - 1;

		while (j >= 0 and arr[j] > x)
			arr[j + 1] = arr[j], j--;

		arr[j + 1] = x;
	}
}

int main()
{
	int n; cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	insertion_sort(arr, n);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
}
