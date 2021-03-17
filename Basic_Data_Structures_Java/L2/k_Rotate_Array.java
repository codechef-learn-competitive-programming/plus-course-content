package Basic_Data_Structures_2;

public class k_Rotate_Array {

	public static void main(String[] args) {
	

		int[] arr = {1, 2, 3, 4, 5, 6, 7};
		
		int k = -1;
		
		int[] res = rotate(arr, k);
		
		for(int val: res) {
			System.out.print(val + " ");
		}
	}
	
	//TC - O(n)
	//SC - O(n)
	private static int[] rotate(int[] arr, int k) {
		

		k = k % arr.length; //4
		
		if(k < 0) {
			k = k + arr.length;
		}
		
		int[] na = new int[arr.length]; //[4, 5, 6, 7, 1 , 2, 3]
		
		for(int i = 0; i < na.length; i++) {
			
			if(i < k) { //i = 3
				na[i] = arr[i + arr.length - k]; //3 + 7 - 4 = 6
			}else {  //i = 4
				na[i] = arr[i - k]; //4 - 4 = 0
			}
		}
		
		return na;
	}

}
