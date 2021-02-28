package Sorting_Searching_Batch_2_Class_1;

public class Bubble_Sort {

	public static void main(String[] args) {
		
		int[] arr = { 3, 13, 12, 4, 7, 5 };

		sort(arr, arr.length);

		System.out.println("----------------");
		for (int val : arr) {
			System.out.print(val + " ");
		}

	}
	
	//Time Complexity - O(n2)
	//Space Complexity - O(1)
	private static void sort(int[] arr, int n) {
		
		for(int i = 0; i < n - 1; i++) {
			
			//i = 0; swaps = 5 (n - 0 - 1)
			//i = 1; swaps = 4; (n - 1 - 1)
			boolean swap = false;
			for(int j = 0; j < n - i - 1; j++) {
				
				if(arr[j] > arr[j + 1]) {
					
					//swap
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					swap = true;
				}
			}
			if(swap == false) {
				break;
			}
			for (int val : arr) {
				System.out.print(val + " ");
			}

			System.out.println();
		}
		
	}

}
