package Basic_Data_Structures_7;

import java.util.Stack;

public class Valid_Paranthesis {

	public static void main(String[] args) {

		String str = "(()";

		
		System.out.println(checkValid(str));

	}

	private static boolean checkValid(String str) {

		Stack<Character> s = new Stack<>();

		for (int i = 0; i < str.length(); i++) {

			char ch = str.charAt(i);

			if (ch == '(' || ch == '[' || ch == '{') {
				s.push(ch);
			} else {
				if (ch == ')' && s.peek() != '(')
					return false;
				if (ch == ']' && s.peek() != '[')
					return false;
				if (ch == '}' && s.peek() != '{')
					return false;
				
				s.pop();
			}

		}
		
		return s.isEmpty();

	}

}
