package Basic_Data_Structures_6;

public class Product_except_self {

	public static void main(String[] args) {
		

		int[]arr = {4, 5, 1, 8, 2};
		
		int[] res = solve(arr);
		
		for(int val: res) {
			System.out.print(val + " ");
		}

	}

	private static int[] solve(int[] arr) {
		

		int[] L = new int[arr.length];
		int[] R = new int[arr.length];
		
		int[] ans = new int[arr.length];
		
		L[0]  = 1;
		
		for(int i = 1; i < arr.length; i++) {
			L[i] = arr[i - 1] * L[i - 1];
		}
		
		R[arr.length - 1] = 1;
		
		for(int i = arr.length - 2; i >= 0; i--) {
			R[i] = arr[i + 1] * R[i + 1];
		}
		
		for(int i = 0; i < arr.length; i++) {
			ans[i] = L[i]*R[i];
		}
		
		return ans;
	}

}
