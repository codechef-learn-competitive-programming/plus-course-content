import java.util.Arrays;

public class MinimumImpossibleSum {
	public static void main(String[] args) {
		System.out.println(minSum(new int[] {4, 12, 2, 1, 3}));
	}
	
	public static long minSum(int[] A) {
		Arrays.sort(A);
		int n = A.length;
		long candidate = 1L;
		for(int i = 0; i < n; i++) {
			if(candidate < A[i]) return candidate;
			else  candidate += A[i];
		}
		
		return candidate;
	}
}
