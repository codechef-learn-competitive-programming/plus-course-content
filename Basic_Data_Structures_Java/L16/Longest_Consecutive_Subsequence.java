package Basic_Data_Structures_16;

import java.util.ArrayList;
import java.util.HashMap;

public class Longest_Consecutive_Subsequence {

	public static void main(String[] args) {

		int[] arr = { 2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6 };

		System.out.println(LCS(arr));

	}

	private static ArrayList<Integer> LCS(int[] arr) {

		HashMap<Integer, Boolean> map = new HashMap<>();

		for (int i = 0; i < arr.length; i++) {
			if (map.containsKey(arr[i] - 1)) {
				map.put(arr[i], false);
			} else {
				map.put(arr[i], true);
			}

			if (map.containsKey(arr[i] + 1)) {
				map.put(arr[i] + 1, false);
			}
		}
		
		ArrayList<Integer> keys = new ArrayList<>(map.keySet());
		
		int maxLength = Integer.MIN_VALUE; //5
		int maxStartingNo = 0; //8
		
		for(int key: keys) {
			if(map.get(key) == true) {
				
				int pStartingNo = key;
				int count = 0;
				
				while(map.containsKey(pStartingNo + count)) {
					count++;
				}
				
				if(count > maxLength) {
					maxLength = count;
					maxStartingNo = pStartingNo;
				}
			}
		}
		

		ArrayList<Integer> res = new ArrayList<>();
		for(int i = 0; i < maxLength; i++) {
			res.add(maxStartingNo + i);
		}
		
		return res;
	}

}
