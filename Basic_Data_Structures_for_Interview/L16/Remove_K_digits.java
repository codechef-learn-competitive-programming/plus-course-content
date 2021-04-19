package Basic_Data_Structures_Batch_2_Class_16;

import java.util.Stack;


public class Remove_K_digits {

	public static void main(String[] args) {
		

		System.out.println(remove("100200", 1));
		//10200 k = 0;
		// 0 2 0 0 
		//res = 
		//zero 
	}

	private static String remove(String num, int k) {
		
		Stack<Character> s = new Stack<>();
		
		for(char digit : num.toCharArray()) {
			
			while(s.size() > 0 && k > 0 && s.peek() > digit) {
				
				s.pop();
				k -= 1;
			}
			
			s.push(digit);
		}
		
		StringBuilder res = new StringBuilder();
		boolean zero = true;
		
		for(char digit: s) {
			System.out.println("digit " + digit);
			if(zero && digit == '0') continue;
			zero = false;
			res.append(digit);
			
			System.out.println(res);
		}
		
		//System.out.println(res.length());
		if(res.length() == 0) return "0";
			
		return res.toString();	
	}

}
