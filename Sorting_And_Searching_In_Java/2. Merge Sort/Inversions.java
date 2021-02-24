import java.util.Arrays;

public class Inversions {
	public static void main(String[] args) {
		inversionCount(new int[] {3, 17, 2, 8, 0, 10, 5, 1});
	}
	
	public static void inversionCount(int[] A) {
		System.out.println(inversionCount(A, 0, A.length - 1));
	}
	
	public static int inversionCount(int[] A, int l, int r) {
		int count = 0;
		if(l < r) {
			int mid = l + (r - l)/2;
			count += inversionCount(A, l, mid);
			count += inversionCount(A, mid + 1, r);
			count += merge(A, l, mid, r);
		}
		
		return count;
	}
	
	public static int merge(int[] A, int l, int mid, int r) {
		int count = 0;
		int[] mergedArray = new int[r - l + 1];
		int i = l, j = mid + 1, k = 0;
		for(k = 0; k < mergedArray.length && i <= mid && j <= r; k++) {
			if(A[i] <= A[j]) mergedArray[k] = A[i++];
			else {
				mergedArray[k] = A[j++];
				count += mid - i + 1;
			}
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
		
		return count;
	}
}
