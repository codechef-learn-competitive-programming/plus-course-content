package Sorting_Searching_1;

public class Insertion_Sort {

	public static void main(String[] args) {

		int[] arr = { 7, 4, 5, 2 };
		insertionSort(arr);

//		for (int val : arr) {
//
//			System.out.print(val + " ");
//		}

	}

	//Time Complexity 
	//O(n2) - Worst Case
	//O(n) - best Case occurs when array is already sorted. 
	//Space Complexity
	//O(1) (In Place Sorting Algo)
 	private static void insertionSort(int[] arr) {

		int n = arr.length;

		
		for (int i = 1; i < n; i++) {

			int key = arr[i];

			int j = i - 1;

			while (j >= 0 && arr[j] > key) {

				// shift
				arr[j + 1] = arr[j];
				j = j - 1;

			}

			arr[j + 1] = key;

//			for (int k = 0; k < arr.length; k++) {
//
//				System.out.print(arr[k] + " ");
//			}
//			System.out.println();
		}

	}

}
