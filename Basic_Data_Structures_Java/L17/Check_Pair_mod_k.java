package Basic_Data_Structures_17;

public class Check_Pair_mod_k {

	public static void main(String[] args) {
		

		int[] arr = {20, 25, 10, 3, 15, 26};
		
		System.out.println(canMakePairs(arr, 10));

	}

	private static boolean canMakePairs(int[] arr, int k) {
		
		int[] frequency = new int[k];
		for(int num: arr) {
			
			num %= k;
			if(num < 0) num += k;
			frequency[num]++;
		}
		
		if(frequency[0] % 2 != 0)  return false;
		
		for(int i = 1; i <= k/2; i++) {
			if(frequency[i] != frequency[k - i]) return false;
		}
		
		return true;
	}

}
