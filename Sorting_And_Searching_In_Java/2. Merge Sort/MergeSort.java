import java.util.Arrays;

public class MergeSort {
	public static void main(String[] args) {
		mergeSort(new int[] {3, 17, 2, 8, 0, 10, 5});
	}
	
	public static void mergeSort(int[] A) {
		mergeSort(A, 0, A.length - 1);
		System.out.println("Sorted : " + Arrays.toString(A));
	}
	
	public static void mergeSort(int[] A, int l, int r) {
		if(l < r) {
			int mid = l + (r - l)/2; //l and r are large numbers (l + r)/2
			mergeSort(A, l, mid);
			mergeSort(A, mid + 1, r);
			merge(A, l, mid, r);
		}
	}
	
	public static void merge(int[] A, int l, int mid, int r) {
		int[] mergedArray = new int[r - l + 1];
		int i = l, j = mid + 1, k = 0;
		for(k = 0; k < mergedArray.length && i <= mid && j <= r; k++) {
			if(A[i] <= A[j]) mergedArray[k] = A[i++];
			else mergedArray[k] = A[j++];
		}
		
		while(i <= mid) {
			mergedArray[k++] = A[i++];
		}
		
		while(j <= r) {
			mergedArray[k++] = A[j++];
		}
		
		k = 0;
		for(i = l; i <= r; i++) {
			A[i] = mergedArray[k++];
		}
	}
}
