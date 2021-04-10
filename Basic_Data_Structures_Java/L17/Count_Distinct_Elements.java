package Basic_Data_Structures_17;

import java.util.HashMap;

public class Count_Distinct_Elements {

	public static void main(String[] args) {
		

		int[] arr = {1, 2, 1, 3, 4, 2, 3};
		
		count(arr, 4);

	}

	//TC - O(n)
	//SC - O(k)
	private static void count(int[] arr, int k) {
		

		HashMap<Integer, Integer> map = new HashMap<>();
		
		for(int i = 0; i < k; i++) {
			map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
		}
		
		System.out.print(map.size() + " ");
		
		for(int i = k; i < arr.length; i++) {
			//the frequecy  of arr[i - k]  will be reduced by 1. 
			//So, if it is already 1, it will become 0 on reduction.
			
			if(map.get(arr[i - k]) == 1) {
				map.remove(arr[i - k]);
			}else {
				
				map.put(arr[i - k], map.get(arr[i - k]) - 1);
			}
			
			map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
			System.out.print(map.size() + " ");
		}
	}

}
