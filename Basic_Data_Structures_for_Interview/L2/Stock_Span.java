package Basic_Data_Structures_Batch_2_Class_2;

import java.util.Stack;

public class Stock_Span {

	public static void main(String[] args) {
		

		int[] arr = {100, 80, 60, 70, 60, 75, 85};
		
		int[] res = stockSpan(arr);
		for(int val: res) {
			System.out.print(val + " ");
		}

	}

	private static int[] stockSpan(int[] arr) {
		
		Stack<Integer> s = new Stack<>();
		
		int[] span = new int[arr.length];
		
		s.push(0);
		span[0] = 1;
		
		for(int i = 1; i < arr.length; i++) {
			
			while(!s.isEmpty() && arr[i] > arr[s.peek()]) {
				s.pop();
			}
			
			if(s.isEmpty()) {
				span[i] = i + 1;
			}else {
				span[i] = i - s.peek();
			}
			
			s.push(i);
		}
		
		return span;
		
		
	}

}
