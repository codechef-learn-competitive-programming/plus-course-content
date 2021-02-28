package Sorting_Searching_3;

public class Quick_Sort {

	public static void main(String[] args) {
		

		int[] arr = {10, 7, 8, 9, 1, 5};
		sort(arr, 0, arr.length - 1);
		
		for(int val: arr) {
			System.out.print(val + " ");
		}

	}

	private static void sort(int[] arr, int low, int high) {
		

		if(low < high) {
			
			//partitioning index
			int pi = partition(arr, low, high);
			
			sort(arr, low, pi - 1);
			sort(arr, pi + 1, high);
		}
		
	}

	private static int partition(int[] arr, int low, int high) {
		
		int pivot = arr[high];
		
		int i = (low - 1); //index of smaller element
		
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
