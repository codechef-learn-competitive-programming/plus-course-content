package Sorting_Searching_6;

import java.util.Scanner;

public class Colour_Me_Yellow {

	public static void main(String[] args) {
		

		Scanner scn = new Scanner(System.in);
		
		int test = scn.nextInt();
		
		while(test--> 0) {
			
			long n = scn.nextLong();
			long red = scn.nextLong();
			long green = scn.nextLong();
			long blue = scn.nextLong();
			
			System.out.println(colour(red, blue, green, n));
		}

	}

	private static long colour(long red, long blue, long green, long n) {
		
		//defining the search space
		
		long left = 0;
		long right = Math.min(n, Math.min(red, blue));
		
		long ans = 0;
		
		while(left <= right) {
		
			//find mid
			//mid represents the no of columns that can be filled.
			long mid = (left + right) / 2;
			
			if(good(red, mid, blue, green)) {
				
				ans = mid;
				left = mid + 1;
			}else {
				right = mid - 1;
			}
		}
		return ans;
	}

	private static boolean good(long red, long mid, long blue, long green) {

		//row = 3;
		//cols = mid;
		//red, blue, green
		
		
		//If I am trying to fill mid columns, then I need atleast
		//mid  no of red and blue tiles. 
		
		//I have two rows of mid no of columns filled by red and blue
		//For the third row of all the mid columns, 
		//I basically need mid no of tiles of any colour. 

		//Tiles left after filling 1st and second row
		return (red - mid) + (blue - mid) + green >= mid;
	}

}
