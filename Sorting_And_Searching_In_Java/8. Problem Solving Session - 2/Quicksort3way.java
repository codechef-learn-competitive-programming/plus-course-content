import java.util.Arrays;

public class Quicksort3way {
	
	public static void main(String[] args) {
		quicksort(new int[] {1, 5, 6, 3, 2, 1, 1, 9, 0, 9, 5, 6});
	}
	
	public static void quicksort(int[] A) {
		quicksort(A, 0, A.length - 1);
		System.out.println(Arrays.toString(A));
	}
	
	//[X,...,X, |P,... P,| X,...X]
	public static void quicksort(int[] A, int l, int r) {
		if(l < r) {
			int[] p = partition(A, l, r);
			quicksort(A, l, p[0] - 1);
			quicksort(A, p[1] + 1, r);
		}
	}
	
	private static int[] partition(int[] A, int l, int r) {
		int i = l, k = r;
		int j = l + 1;
		int key = A[l];
		while(j <= k) {
			if(A[j] < key) {
				swap(A, j, i);
				i++;
				j++;
			} else if (A[j] > key) {
				swap(A, j, k);
				k--;
			} else {
				j++;
			}
		}
		
		return new int[] {i, k};
	}
	
	private static void swap(int[] A, int x, int y) {
		int temp = A[x];
		A[x] = A[y];
		A[y] = temp;
	}

}
