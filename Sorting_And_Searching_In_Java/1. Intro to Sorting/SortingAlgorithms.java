import java.util.Arrays;

public class SortingAlgorithms {
	public static void main(String[] args) {
		bubbleSort(new int[] {5, 3, 4, 10, 9, 6, 1});
		bubbleSortOptimized(new int[] {5, 3, 4, 10, 9, 6, 1});
		bubbleSortOptimized(new int[] {1, 2, 3, 4, 5});
		insertionSort(new int[] {5, 3, 4, 10, 9, 6, 1});
		selectionSort(new int[] {5, 3, 4, 10, 9, 6, 1});
	}
	
	public static void bubbleSort(int[] A) {
		int N = A.length;
		for(int i = 0; i < N; i++) { //Controls the passes
			for(int j = 0; j < N - i - 1; j++) {//Adjacent element scanning loop
				if(A[j] > A[j + 1]) {
					int temp = A[j + 1];
					A[j + 1] = A[j];
					A[j] = temp;
				}
			}
		}
		
		System.out.println("Bubble sorted : " + Arrays.toString(A));
	}
	
	public static void bubbleSortOptimized(int[] A) {
		int N = A.length;
		for(int i = 0; i < N; i++) { //Controls the passes
			boolean swapped = false;
			for(int j = 0; j < N - i - 1; j++) {//Adjacent element scanning loop
				if(A[j] > A[j + 1]) {
					int temp = A[j + 1];
					A[j + 1] = A[j];
					A[j] = temp;
					swapped = true;
				}
			}
			
			if(!swapped) {
				System.out.println("Pass - " + (i + 1));
				break;
			}
		}
		
		System.out.println("Optimized Bubble sorted : " + Arrays.toString(A));
	}
	
	//E.g: [1, 2, 3, 4, 5] -> O(N) since while loop never gets executed.
	public static void insertionSort(int[] A) {
		int N = A.length;
		for(int i = 1; i < N; i++) {
			int key = A[i]; //Card that I'm getting from dealer
			int j = i - 1;
			
			while(j >= 0 && A[j] > key) { //Shift all elements > key to right
				A[j + 1] = A[j];
				j--;
			}
			
			A[j + 1] = key; //Insert in the empty space after shifting
		}
		
		System.out.println("Insertion sorted : " + Arrays.toString(A));
	}
	
	public static void selectionSort(int[] A) {
		int N = A.length;
		for(int i = 0; i < N; i++) {
			int minIdx = i;
			for(int j = i + 1; j < N; j++) {
				if(A[j] < A[minIdx]) minIdx = j;
			}
			
			if(minIdx != i) {
				int temp = A[minIdx];
				A[minIdx] = A[i];
				A[i] = temp;
			}
		}
		
		System.out.println("Selection sorted : " + Arrays.toString(A));
	}
}
