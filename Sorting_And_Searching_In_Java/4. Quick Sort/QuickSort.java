import java.util.Arrays;

public class QuickSort {
	public static void main(String[] args) {
		quickSort(new int[] {5, 27, 3, 45, 30, 19, 77, 1, 20});
		quickSort(new int[] {1, 2, 3, 4, 5});
		quickSort(new int[] {5, 4, 3, 2, 1});
	}
	
	public static void quickSort(int[] A) {
		quickSort(A, 0, A.length - 1);
		System.out.println(Arrays.toString(A));
	}
	
	public static void quickSort(int[] A, int l, int r) {
		if(l < r) {
			int pI = partition(A, l, r);
			quickSort(A, l, pI - 1);
			quickSort(A, pI + 1, r);
		}
	}
	
	public static int partition(int[] arr, int low, int high) {
		int pivot = arr[high];
		int i = low;
		for(int j = low; j < high; j++) {
			if(arr[j] < pivot) {
				swap(arr, i, j);
				i++;
			}
		}
		
		swap(arr, i, high); //Positioning pivot at correct location
		return i;
	}
	
	private static void swap(int[] A, int x, int y) {
		int temp = A[x];
		A[x] = A[y];
		A[y] = temp;
	}
}
