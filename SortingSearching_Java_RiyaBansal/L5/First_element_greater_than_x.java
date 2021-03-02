package Sorting_Searching_5;

public class First_element_greater_than_x {

	public static void main(String[] args) {
		
		int[] arr = { 2, 3, 5, 6, 8, 10, 12 };

		System.out.println(Search(arr, 4));

	}

	private static int Search(int[] arr, int x) {

		// search space
		int low = 0;
		int high = arr.length - 1;

		int ans = -1;
		while (low <= high) {

			int mid = (low + high) / 2;
			if (arr[mid] >= x) {
				ans = mid;
				high = mid - 1;
			}else {
				low = mid + 1;
			}
		}

		return ans;

	}

}
