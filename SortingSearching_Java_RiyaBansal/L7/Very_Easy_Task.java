package Sorting_Searching_7;

import java.util.Scanner;

public class Very_Easy_Task {

	public static void main(String[] args) {
		

		Scanner scn = new Scanner(System.in);
		
		int n = scn.nextInt(); //no of copies required
		
		int x = scn.nextInt();
		int y = scn.nextInt();
		
		System.out.println(min_time(n, x, y));

	}

	private static int min_time(int n, int x, int y) {
		
		if(n == 1) {
			return Math.min(x, y);
		}
		
		int left = 0;
		int right = Math.max(x, y)*n;
		
		int ans = 0;
		
		while(left <= right) {
			
			//mid represents the time it takes to make n copies
			
			int mid = (left + right) / 2;
			
			if(good(n, x, y, mid)) {
				ans  = mid;
				right = mid - 1;
			}else {
				
				left = mid + 1;
			}
		}
		
		return ans + Math.min(x, y);
		

	}

	private static boolean good(int n, int x, int y, int mid) {
		
		//How to check if a time is big enough to make all the copies
		//or not
		
		
		//If I have mid time, and the speed of copier 1 is x,
		//Then I can make mid/x copies in mid seconds. 
		
		//If I have mid time, and the speed of copier 2 is y,
		//Then I can make mid/y copies in mid seconds. 
		
		return (mid/x) + (mid/y) >= n - 1;
	}

}
