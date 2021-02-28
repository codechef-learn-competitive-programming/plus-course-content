package Sorting_Searching_Batch_2_Class_1;

public class Selection_Sort {

	public static void main(String[] args) {
		

		int[] arr = { 3, 13, 12, 4, 7, 5 };

		sort(arr, arr.length);

		System.out.println("----------------");
		for (int val : arr) {
			System.out.print(val + " ");
		}

	}

	private static void sort(int[] arr, int n) {
		

		for(int i = 0; i < n - 1; i++) {
			
			//Find the min element in unsorted array
			int min_idx = i;
			for(int j = i + 1; j < n; j++) {
				
				if(arr[j] < arr[min_idx]) {
					
					min_idx  = j;
				}
			}
			
			//swapping the min element with the first element
			int temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;
			
			for (int val : arr) {
				System.out.print(val + " ");
			}
			System.out.println();
		}
		
	}

}
