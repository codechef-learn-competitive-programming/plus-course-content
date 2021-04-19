package Basic_Data_Structures_16;

import java.util.ArrayList;
import java.util.HashMap;

public class Intersection {

	public static void main(String[] args) {

		int[] arr1 = { 5, 5, 7, 7, 2, 5 };
		int[] arr2 = { 6, 7, 9, 5, 5, 5, 5 };

		System.out.println(intersection(arr1, arr2));
	}

	//TC - O(Max (n, m))
	//SC - O(Max (n, m))
	private static ArrayList<Integer> intersection(int[] a1, int[] a2) {

		ArrayList<Integer> ans = new ArrayList<>();

		HashMap<Integer, Integer> map = new HashMap<>();

		for (int i = 0; i < a1.length; i++) {
			map.put(a1[i], map.getOrDefault(a1[i], 0) + 1);
		}
		
		for(int i = 0; i < a2.length; i++) {
			if(map.containsKey(a2[i]) && map.get(a2[i]) > 0) {
				ans.add(a2[i]);
				
				int of = map.get(a2[i]);
				int nf = of - 1;
				map.put(a2[i], nf);
			}
		}
		
		return ans;
	}

}
