package Basic_Data_Structures_1;

public class ArraysDemo {

	public static void main(String[] args) {

		// [] means that I am trying to create an array.
		// Integer
		// arr is a reference to an array.
		// But it not pointing anywhere right now.
		
		int[] arr;
		// int arr1[]; //C++

		// declared and instantiated
		arr = new int[5];
		System.out.println(arr);

		System.out.println(arr.length);

		// get
		System.out.println(arr[0]);
		System.out.println(arr[1]);
		System.out.println(arr[2]);
		System.out.println(arr[3]);
		System.out.println(arr[4]);

		// System.out.println(arr[5]);

		// set

		arr[0] = 10;
		arr[1] = 20;
		arr[2] = 30;
		arr[3] = 40;
		arr[4] = 50;

		System.out.println(arr[0]);
		System.out.println(arr[1]);
		System.out.println(arr[2]);
		System.out.println(arr[3]);
		System.out.println(arr[4]);

		// loop
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}

		System.out.println();
		// enhanced loop
		System.out.println("---------------");
		for (int val : arr) {
			System.out.println(val);
		}

		int i = 0;
		int j = 2;

		// non working swap
//		System.out.println("---------------------");
//		System.out.println(arr[i] + ", " + arr[j]);
//		swap(arr[i], arr[j]);
//		System.out.println(arr[i] + ", " + arr[j]);
//
//		// working swap
//		System.out.println("---------------------");
//		System.out.println(arr[i] + ", " + arr[j]);
//		swap(arr, i, j);
//		System.out.println(arr[i] + ", " + arr[j]);

		System.out.println("---------------------");
		int[] other = { 1000, 200, 300 };
		System.out.println(arr[0] + ", " + other[0]);
		swap(arr, other);
		System.out.println(arr[0] + ", " + other[0]);
	}

	private static void swap(int[] one, int[] two) {

		int[] temp = one; //[10, 20, 30, 40, 50]
		one = two;  //[100, 200, 300]
		two = temp; //[10, 20, 30, 40, 50]

	}

	private static void swap(int[] arr, int i, int j) {

		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;

	}

	private static void swap(int one, int two) {

		int temp = one;
		one = two;
		two = temp;
	}

}
