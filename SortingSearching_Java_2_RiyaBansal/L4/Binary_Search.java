package Sorting_Searching_Batch_2_Class_4;

public class Binary_Search {

	public static void main(String[] args) {
		

		int[] arr = {3, 5, 7, 9, 11, 13, 14, 22, 34};
		
		System.out.println(binarySearch(arr, 14));

	}

	private static int binarySearch(int[] arr, int i) {

		int low = 0;
		int high = arr.length - 1;
		
		while(low <= high) {
			
			int mid = (low + high) / 2;
			
			if(arr[mid] == i) {
				return mid;
			}else if(arr[mid] < i) {
				low = mid + 1;
			}else {
				high = mid -1;
			}
		}
		
		return -1;
	}

}
