package Sorting_Searching_7;

import java.util.Arrays;
import java.util.Scanner;

public class Aggressive_Cows {

	public static void main(String[] args) {

		Scanner scn = new Scanner(System.in);

		int n = scn.nextInt(); // no of stalls
		int c = scn.nextInt(); // no of cows

		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;

		int[] arr = new int[n];

		for (int i = 0; i < n; i++) {

			arr[i] = scn.nextInt();

			if (arr[i] > max) {
				max = arr[i];
			}

			if (arr[i] < min) {
				min = arr[i];
			}
		}

		System.out.println(distribution(arr, c, max));

	}

	//Time Complexity - O(nlogn)
	private static int distribution(int[] arr, int cows, int max) {

		Arrays.sort(arr);

		int lo = 1;
		int hi = max;

		int result = 0;

		while (lo <= hi) {

			// mid represents the min distance between the cows
			int mid = (lo + hi) / 2;

			if (good(cows, mid, arr)) {

				result = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		return result;
	}

	private static boolean good(int cows, int mid, int[] arr) {

		// For a distance (mid) to be good
		// 1. all cows should be atleast mid distance apart
		// 2. Exactly k cows should be able to be placed in the stalls.

		// For the 1st cow, the optimal position to place it is at the 1st position -
		// arr[0]

		// No of cows placed
		int count = 1;

		// storing the position where the last cow is placed.
		int last_pos = arr[0];

		for (int i = 1; i < arr.length; i++) {

			if (arr[i] - last_pos >= mid) {
				count++;
				last_pos = arr[i];
			}

			if (count == cows) {
				return true;
			}
		}

		return false;
	}

}
