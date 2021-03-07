package Sorting_Searching_Batch_2_Class_5;

import java.util.Scanner;

public class Colour_Me_Yellow {

	public static void main(String[] args) {
		

		Scanner scn = new Scanner(System.in);
		
		int test = scn.nextInt();
		while(test-- > 0) {
			
			long n = scn.nextLong();
			long red = scn.nextLong();
			long green = scn.nextLong();
			long blue = scn.nextLong();
			
			System.out.println(colour(red, blue, green, n));
		}

	}

	private static long colour(long red, long blue, long green, long n) {
		
		//range of no of columns that can be filled
		long left = 0;
		long right = Math.min(n, Math.min(red, blue));
		
		long ans = 0;
		
		while(left <= right) {
			
			//mid represents the no columns that I can fill
			
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
		//cols = mid
		// mid * 3 matrix
		//red, blue, green
		
		//If I am trying to fill mid columns, then I need atleast
		//mid no of red and blue tiles
		
		//First row of every col will be filled by red colour and
		//second row of every col will be filled by blue colour
		
		//For the third row, I need tiles of any colour. 
		return (red - mid) + (blue - mid) + green >= mid;
		
	}

}
