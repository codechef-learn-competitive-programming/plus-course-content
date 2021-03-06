package Sorting_Searching_7;

public class ComparatorDemo {

	public static void main(String[] args) {

		Car[] cars = new Car[5];
		cars[0] = new Car(900, 5, "Yellow");
		cars[1] = new Car(100, 50, "Black");
		cars[2] = new Car(2000, 90, "Red");
		cars[3] = new Car(7000, 3, "Orange");
		cars[4] = new Car(1300, 800, "Blue");

		bubbleSort(cars);
		display(cars);
		
		

	}

	private static void bubbleSort(Car[] arr) {

		int n = arr.length;

		for (int i = 0; i < n - 1; i++) {

			for (int j = 0; j < n - i - 1; j++) {

				if (arr[j].compareTo(arr[j + 1]) > 0) {

					Car temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}

		}
	}

	public static <T> void display(T[] arr) {
		for (T val : arr)
			System.out.println(val);
	}

}