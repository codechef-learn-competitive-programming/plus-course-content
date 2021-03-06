package Sorting_Searching_Batch_2_Class_3;

public class Quick_Sort {

	public static void main(String[] args) {

		int[] arr = { 10, 7, 4, 9, 1, 5 };
		sort(arr, 0, arr.length - 1);

	}

	private static void sort(int[] arr, int low, int high) {
		
		if(low < high) {
			
			//index of pivot element after partitioning is done
			int pi = partition(arr, low, high);
			
			sort(arr, low, pi - 1);
			sort(arr, pi + 1, high);
		}
	}

	private static int partition(int[] arr, int low, int high) {
		

		//pivot as last ele of arrray
		int pivot = arr[high];
		int i = (low - 1); //index of end of region of smaller elements
		
		for(int j = low; j < high; j++) {
			
			if(arr[j] < pivot) {
				i++;
				//swap
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		
		//swap arr[i + 1] and arr[high]
		int temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;
		
		return i + 1;
	}

}
