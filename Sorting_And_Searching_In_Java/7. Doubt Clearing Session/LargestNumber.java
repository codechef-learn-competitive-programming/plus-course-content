import java.util.Arrays;

public class LargestNumber {
	public static void main(String[] args) {
		System.out.println(largestNumber(new int[] {3, 30, 34, 5, 9}));
	}
	
	public static String largestNumber(int[] nums) {
		String[] array = new String[nums.length];
		for(int i = 0; i < nums.length; i++) {
			array[i] = String.valueOf(nums[i]);
		}
		
		//a="100", b = "90"  "90100" > "10090"
		Arrays.sort(array, (a, b) -> (b + a).compareTo(a + b));
		if(array[0].equals("0")) return "0";
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < array.length; i++) {
			sb.append(array[i]);
		}
		
		return sb.toString();
	}
}
