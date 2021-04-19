package Basic_Data_Structures_16;

import java.util.HashMap;

public class Subarray_sum_equals_k {

	public static void main(String[] args) {

		int[] arr = { 3, 4, 7, 2, -3, 1, 4, 2 };

		System.out.println(find(arr, 7));

	}

	private static int find(int[] arr, int k) {

		HashMap<Integer, Integer> map = new HashMap<>();
		int count = 0;
		int sum = 0;
		
		map.put(0, 1);
		for (int i = 0; i < arr.length; i++) {

			sum += arr[i];
			if (map.containsKey(sum - k)) {
				count += map.get(sum - k);
			}

			map.put(sum, map.getOrDefault(sum, 0) + 1);
		}

		return count;
	}

}
