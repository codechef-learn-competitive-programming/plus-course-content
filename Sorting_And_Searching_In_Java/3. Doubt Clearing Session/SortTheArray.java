import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SortTheArray {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[] ar = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			ar[i] = Integer.parseInt(st.nextToken());
		}
		
		sortTheArray(ar);
	}
	
	public static void sortTheArray(int[] ar) {
		int n = ar.length;
		int[] copy = Arrays.copyOf(ar, n);
		Arrays.sort(copy); //O(n * log n)
		int L = -1, R = -1;
		for(int i = 0; i < n; i++) {
			if(ar[i] != copy[i]) {
				L = i;
				break;
			}
		}
		
		for(int i = n - 1; i >= 0; i--) {
			if(ar[i] != copy[i]) {
				R = i;
				break;
			}
		}
		
		if(L == -1 && R == -1) {
			System.out.println("yes");
			System.out.println("1 1");
			return;
		} 
		
		reverse(ar, L, R);
		if(isSorted(ar)) {
			System.out.println("yes");
			System.out.println((L + 1) + " " + (R + 1));
		} else {
			System.out.println("no");
		}
	}
	
	public static void reverse(int[] A, int l, int r) {
		while(l < r) {
			int temp = A[l];
			A[l] = A[r];
			A[r] = temp;
			l++;
			r--;
		}
	}
	
	private static boolean isSorted(int[] ar) {
		int n = ar.length;
		for(int i = 1; i < n; i++) {
			if(ar[i] < ar[i - 1]) return false;
		}
		return true;
	}
}
