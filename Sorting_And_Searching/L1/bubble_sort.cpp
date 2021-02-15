#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int *arr, int n)
{
	for (int iter = 0; iter < n - 1; ++iter)
	{
		bool swapped = false;

		for (int i = 0; i + 1 < n - iter; ++i)
			if (arr[i] > arr[i + 1])
				swap(arr[i], arr[i + 1]), swapped = true;

		if (!swapped)
			break;
	}
}

int main()
{
	int n; cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	bubble_sort(arr, n);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
}
