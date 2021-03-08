import java.util.Arrays;

public class Sort3Numbers {
	public static void main(String[] args) {
		sort(new int[] {2, 0, 2, 1, 1, 0, 2, 2, 1, 0, 0, 1});
	}
	
	public static void sort(int[] A) {
		int zero = 0, one = 0, two = A.length - 1;
		while(one <= two) {
			switch(A[one]) {
			case 0: swap(A, one, zero);
				    zero++;
				    one++;
				    break;
			case 1: one++;
					break;
			case 2: swap(A, one, two);
				    two--;
				    break;
			}
		}
		
		System.out.println(Arrays.toString(A));
	}
	
	private static void swap(int[] A, int x, int y) {
		int temp = A[x];
		A[x] = A[y];
		A[y] = temp;
	}
}

