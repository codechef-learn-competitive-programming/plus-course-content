package Basic_Data_Structures_Batch_2_Class_1;

import java.util.Stack;

public class Valid_Paranthesis {

	public static void main(String[] args) {
		

		System.out.println(validParanthesis("[([]{})()])"));

	}

	private static boolean validParanthesis(String string) {
		
		Stack<Character> s = new Stack<>();

		for(int i = 0; i < string.length(); i++) {
			
			char ch = string.charAt(i);
			
			if(ch == '[' || ch == '{' || ch == '(') {
				
				s.push(ch);
			}else {
				if(s.isEmpty()) return false;
				
				if(ch == ']' && s.peek() != '[') return false;
				else if(ch == '}' && s.peek() != '{') return false;
				else if(ch == ')' && s.peek() != '(') return false;
				else s.pop();
			}
		}
		
		return true;
		
	}

}
