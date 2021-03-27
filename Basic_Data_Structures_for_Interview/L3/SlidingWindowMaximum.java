package Basic_Data_Structures_Batch_2_Class_3;

import java.util.Deque;
import java.util.LinkedList;

public class SlidingWindowMaximum {

	public static void main(String[] args) {

		int[] arr = { 2, 3, -10, -4, 11, 6, 3, 2, 0 };

		int k = 3;

		print(arr, k);

	}

	private static void print(int[] arr, int k) {

		Deque<Integer> qi = new LinkedList<>();

		int i;
		for (i = 0; i < k; i++) {

			while (!qi.isEmpty() && arr[i] >= arr[qi.peekLast()])
				qi.removeLast();

			qi.addLast(i);
		}

		for (; i < arr.length; i++) {

			System.out.println(arr[qi.peek()] + " ");

			while (!qi.isEmpty() && qi.peek() <= i - k)
				qi.removeFirst();

			while (!qi.isEmpty() && arr[i] >= arr[qi.peekLast()])
				qi.removeLast();

			qi.addLast(i);
		}

		System.out.println(arr[qi.peek()]);

	}

}
