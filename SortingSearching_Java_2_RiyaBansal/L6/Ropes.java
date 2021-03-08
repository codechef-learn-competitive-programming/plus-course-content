package Sorting_Searching_Batch_2_Class_6;

import java.util.Scanner;

public class Ropes {

	public static void main(String[] args) {
		

		Scanner scn = new Scanner(System.in);
		
		int n = scn.nextInt(); // no of ropes
		int k = scn.nextInt(); //no of pieces
		
		int[] ropes = new int[n];
		
		for(int i = 0; i < n; i++) {
			ropes[i] = scn.nextInt();
			
		}
		
		double l = 0;
		double r = 1e8;
		
		for(int i = 0; i < 100; i++) {
			
			double m = (l + r) / 2;
			if(good(m, k, n, ropes)) {
				l = m;
			}else {
				r = m;
			}
		}
		
		System.out.println(String.format("%.20f", l));
	}

	private static boolean good(double m, int k, int n, int[] ropes) {
		
		//length of each piece is m
		//Check if I can cut k pieces of length m
		
		int count = 0;
		
		for(int i = 0; i < n; i++) {
			
			//length of rope - ropes[i]
			//length of single piece - m
			
			count += Math.floor(ropes[i] / m);
			
		}
		
		return count >= k;
			
	}

}
