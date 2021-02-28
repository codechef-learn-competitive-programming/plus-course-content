package Sorting_Searching_Batch_2_Class_1;

public class Insertion_Sort {

	public static void main(String[] args) {

		int[] arr = { 3, 13, 12, 4, 7, 5 };

		sort(arr, arr.length);

		System.out.println("----------------");
		for (int val : arr) {
			System.out.print(val + " ");
		}

	}

	//Time Complexity: Worst Case - O(n2)
	//Time Complexity: Best Case - O(n) [Array is already sorted.]
	//Space Complexity - O(1) [In-Place Algorithm]
	private static void sort(int[] arr, int length) {
		

		int n = arr.length;
		
		for(int i = 1; i < n; i++) {
			
			int key = arr[i];
			
			int j = i - 1;
			while(j >= 0 && arr[j] > key) {
				
				//shift
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			
			arr[j + 1] = key;
			
			System.out.println(i);
			
			for (int val : arr) {
				System.out.print(val + " ");
			}
			
			System.out.println();
		}
		
	}

}
