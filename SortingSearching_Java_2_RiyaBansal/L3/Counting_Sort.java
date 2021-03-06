package Sorting_Searching_Batch_2_Class_3;

import java.util.Arrays;

public class Counting_Sort {

	public static void main(String[] args) {

		int[] data = { 4, 2, 2, 8, 3, 3, 1 };

		int size = data.length;

		countSort(data, size);

		for (int val : data) {
			System.out.print(val + " ");
		}

	}

	private static void countSort(int[] array, int size) {

		int[] output = new int[size + 1];

		// Find the max element of the array
		
		int max = array[0];
		
		//O(n)
		for (int i = 1; i < size; i++) {

			if (array[i] > max) {
				max = array[i];
			}
		}

		int[] count = new int[max + 1];

		Arrays.fill(count, 0);

		// Store the freq of each element
		//O(n)
		for (int i = 0; i < size; i++) {

			count[array[i]]++;
		}

		// Store the cumm sum of the array
		
		//O(max)
		for (int i = 1; i <= max; i++) {

			count[i] += count[i - 1];
		}

		//O(n)
		for (int i = size - 1; i >= 0; i--) {

			output[count[array[i]] - 1] = array[i];
			count[array[i]]--;
		}

		//O(n)
		for (int i = 0; i < size; i++) {
			array[i] = output[i];
		}

	}

}
