package Sorting_Searching_3;

public class Inversion_Count {

	public static void main(String[] args) {

		int[] arr = { 3, 5, 1, 8, 6, 4 };

		System.out.println(inversionCount(arr, 0, arr.length - 1));

	}

	private static long inversionCount(int[] arr, int l, int r) {

		long count = 0;

		if (r > l) {

			int mid = (l + r) / 2;
			count += inversionCount(arr, l, mid);
			count += inversionCount(arr, mid + 1, r);

			count += merge(arr, l, mid, r);

			return count;

		}
		return count;
	}

	public static int[] temp = new int[200009];

	private static long merge(int[] arr, int l, int mid, int r) {

		int i = l;
		int j = mid + 1;

		long swaps = 0;

		int k = 0;
		while (i <= mid && j <= r) {

			if (arr[i] <= arr[j]) {
				temp[k] = arr[i];
				i++;
				k++;
			} else {
				temp[k] = arr[j];
				j++;
				k++;
				swaps += (mid - i + 1);
			}
		}

		while (i <= mid) {

			temp[k] = arr[i];
			k++;
			i++;
		}

		while (j <= r) {

			temp[k] = arr[i];
			k++;
			j++;
		}

		for (int m = l, p = 0; m <= r; m++, p++) {
			arr[m] = temp[p];
		}

		return swaps;
	}

}
