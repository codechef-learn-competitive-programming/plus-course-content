package Sorting_Searching_Batch_2_Class_6;

import java.util.Arrays;
import java.util.Scanner;

public class Aggressive_Cows {

	//Minimax Problems
	public static void main(String[] args) {
		

		Scanner scn = new Scanner(System.in);
		
		int n = scn.nextInt();  //no of stalls
		int c = scn.nextInt(); //no of cows
		
		int[] arr = new int[n];
		//[1, 2, 4, 8, 9]
		int max = Integer.MIN_VALUE;
		for(int i = 0; i < arr.length; i++) {
			arr[i] = scn.nextInt();
			
			if(arr[i] > max) {
				max = arr[i];
			}
		}
		
		distributeCows(n, c, arr, max);
		

	}

	private static int distributeCows(int n, int c, int[] arr, int max) {
		
		Arrays.sort(arr);
		//Defining the search space
		int low = 0;
		int high = max; //9
		
		int ans = 0;
		while(low <= high) {
			
			int mid = (low + high) / 2;
			
			if(good(mid, n, c, arr)) {
				
				ans = mid;
				low = mid + 1;
			}else {
				high = mid - 1;
			}
		}
		
		return ans;
	}

	private static boolean good(int mid, int n, int c, int[] arr) {
		
		//Decide whether mid is good or not. 
		
		//We have to check whether we can place all the C cows atleast mid
		//distance apart. 
		
		//storing no of cows placed
		int count = 1;
		
		//storing the position of last cow that was placed. 
		
		int last_pos = arr[0];
		//[1, 2, 4, 8, 9]
		
		
		for(int i = 1; i < arr.length; i++) {
			
			if(arr[i] - last_pos >= mid) {
				last_pos = arr[i];
			}
			
			if(count == c) {
				return true;
			}
			
		}
		
		return false;
	
	}

}
