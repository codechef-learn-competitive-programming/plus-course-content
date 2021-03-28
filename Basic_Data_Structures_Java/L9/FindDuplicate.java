package Basic_Data_Structures_9;

public class FindDuplicate {

	public static void main(String[] args) {

		int[] arr = { 2, 6, 4, 1, 3, 1, 5 };

		System.out.println(findDuplicates(arr));

	}

	private static int findDuplicates(int[] arr) {

		int slow = arr[0];
		int fast = arr[0];

		do {
			slow = arr[slow];
			fast = arr[arr[fast]];
		} while (slow != fast);
		
		//find entrance
		
		slow = arr[0];
		while(slow != fast) {
			
			slow = arr[slow];
			fast = arr[fast];
		}
		
		return fast;

	}

}
