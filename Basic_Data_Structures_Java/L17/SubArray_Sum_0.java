package Basic_Data_Structures_17;

import Micro_Course_Hashing_1.HashMap;

public class SubArray_Sum_0 {

	public static void main(String[] args) {
		

		int[] arr = {15, -2, 2, -8, 1, 7, 10};
		
		System.out.println(find(arr));

	}

	private static int find(int[] arr) {
		
		HashMap<Integer, Integer> map = new HashMap<>();
		
		int sum = 0;
		int maxLen = 0;
		
		for(int i = 0; i < arr.length; i++) {
			
			sum += arr[i];
			
			if(arr[i] == 0 && maxLen == 0) {
				maxLen = 1;
			}
			
			if(sum == 0) {
				maxLen = i + 1;
			}
			
			Integer prev = map.get(sum);
			
			if(prev != null) {
				maxLen = Math.max(maxLen, i - prev);
			}else {
				map.put(sum, i);
			}
		}
		
		return maxLen;
		
	}

}
