package Basic_Data_Structures_23;

import java.util.HashMap;
import java.util.PriorityQueue;

public class Top_K_frequent_elements {

	public static void main(String[] args) {
		

		int[] arr = {1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5};
		int[] res = topK(arr, 3);
		for(int val: res) {
			System.out.println(val);
		}

	}

	private static int[] topK(int[] arr, int k) {
		
		if(k == arr.length) {
			return arr;
		}
		
		HashMap<Integer, Integer> map = new HashMap<>();
		
		for(int n: arr) {
			map.put(n, map.getOrDefault(n, 0) + 1);
		}
		
		PriorityQueue<Integer> heap = new PriorityQueue<>(
				(n1, n2) -> map.get(n1) - map.get(n2));
		
		for(int n: map.keySet()) {
			heap.add(n);
			if(heap.size() > k) heap.poll();
		}
		
		int[] res = new int[k];
		for(int i = k - 1; i >= 0; i--) {
			res[i] = heap.poll();
		}
		
		return res;
		
	}

}
