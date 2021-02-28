package Sorting_Searching_1;

public class Bubble_Sort {

	public static void main(String[] args) {

		int[] arr = {5, 1, 4, 2, 8 };
		bubbleSort(arr);

//		for (int val : arr) {
//
//			System.out.print(val + " ");
//		}

	}
	
	//Time Complexity
	//O(n2) - Worst Case
	//O(n) - Best Case
	//Space Complexity
	//O(1)(In-Place Sorting Algo)
	private static void bubbleSort(int[] arr) {

		int n = arr.length;

		boolean swapped;
		for (int i = 0; i < n - 1; i++) {
			
			swapped = false;
			for (int j = 0; j < n - i - 1; j++) {

				
				if (arr[j] > arr[j + 1]) {

					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					swapped = true;
				}
			}
			
			for (int k = 0; k < arr.length; k++) {

				System.out.print(arr[k] + " ");
			}
			System.out.println();
			
			if(swapped == false) {
				break;
			}
			
		}

	}

}
