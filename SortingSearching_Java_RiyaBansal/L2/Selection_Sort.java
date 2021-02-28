package Sorting_Searching_2;

public class Selection_Sort {

	public static void main(String[] args) {
		

		int[] arr = { 7, 4, 5, 2, 3, 1, 9, 6 };
		selectionSort(arr);

	}

	private static void selectionSort(int[] arr) {
		

		for(int i = 0; i < arr.length - 1; i++) {
			
			//Find the min element in unsorted array
			int min_idx = i;
			
			for(int j = i + 1; j < arr.length; j++) {
				
				if(arr[j] < arr[min_idx])
					min_idx = j;
			}
			
			//swap the min element with first element
			int temp = arr[min_idx];
			arr[min_idx]  = arr[i];
			arr[i] = temp;
			
			for(int val: arr) {
				System.out.print(val + " ");
			}
			
			System.out.println();
			
		}
		
		
	}

}
