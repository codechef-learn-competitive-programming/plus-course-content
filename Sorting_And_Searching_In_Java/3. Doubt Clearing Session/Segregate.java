import java.util.Arrays;

public class Segregate {
	public static void main(String[] args) {
		segregateNaive(new int[] {50, 10, -1, 27, -19, 3, -44, -12});
		segregate(new int[] {50, 10, -1, 27, -19, 3, -44, -12});
		segregate(new int[] {-1, -19, -44, -12});
	}
	
	public static void segregate(int[] A) {
		segregate(A, 0, A.length - 1);
		System.out.println(Arrays.toString(A));
	}
	
	//T(n) = 2 * T(n/2) + O(n)
	//T(n) = O(n * log n)
	public static void segregate(int[] A, int l, int r) {
		if(l < r) {
			int mid = l + (r - l)/2;
			segregate(A, l, mid); //T(n/2)
			segregate(A, mid + 1, r); //T(n/2)
			merge(A, l, mid, r);//O(n)
		}
	}
	
	//A = [NNNNN,PPPPP | NNNNN, PPPPPP]
	//O(n)
	public static void merge(int[] A, int l, int mid, int r) {
		int k1 = l; //First index of positive in left half
		int k2 = mid + 1;//First index of positive in right half;
		
		while(k1 <= mid && A[k1] < 0) k1++; //O(n)
		while(k2 <= r && A[k2] < 0) k2++; //O(n)
		reverse(A, k1, mid); //O(n)
		reverse(A, mid + 1, k2 - 1);//O(n)
		reverse(A, k1, k2 - 1);//O(n)
	}
	
	
	//[1, 2, 3, 4] => [4, 2, 3, 1] => [4, 3, 2, 1]
	//O(n)
	public static void reverse(int[] A, int l, int r) {
		while(l < r) {
			int temp = A[l];
			A[l] = A[r];
			A[r] = temp;
			l++;
			r--;
		}
	}
	
	
	public static void segregateNaive(int[] A) {
		int N = A.length;
		int[] negatives = new int[N]; int negativeSize = 0;
		int[] positives = new int[N]; int positiveSize = 0;
		for(int i = 0; i < N; i++) {
			if(A[i] < 0) {
				negatives[negativeSize++] = A[i];
			} else {
				positives[positiveSize++] = A[i];
			}
		}
		
		for(int i = 0; i < negativeSize; i++) {
			A[i] = negatives[i];
		}
		
		for(int i = 0; i < positiveSize; i++) {
			A[i + negativeSize] = positives[i];
		}
		
		System.out.println(Arrays.toString(A));
	}
}
