package Basic_Data_Structures_22;

import java.util.PriorityQueue;

public class K_Closest_Point {

	public static void main(String[] args) {
		

		int x[] = {3, 5, -2};
		int y[] = {3, -1, 4};
		
		kClosest(x, y, 2);

	}

	static class Pair implements Comparable<Pair>{
		
		int first;
		int second;
		
		Pair(int a, int b){
			this.first = a;
			this.second = b;
			
		}

		@Override
		public int compareTo(Pair other) {
			
			int x1 = first * first;
			int y1 = second * second;
			int x2 = other.first * other.first;
			int y2 = other.second * other.second;
			
			return (x1 + y1) - (x2 + y2);
			
		}
		
		
	}
	private static void kClosest(int[] x, int[] y, int k) {
		

		PriorityQueue<Pair> pq = new PriorityQueue<>();
		
		for(int i = 0; i < x.length; i++) {
			pq.add(new Pair(x[i], y[i]));
		}
		
		for(int i = 0; i < k; i++) {
			Pair p = pq.poll();
			System.out.println(p.first + " " + p.second);
		}
	}

}
