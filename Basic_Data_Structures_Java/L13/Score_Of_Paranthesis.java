package Basic_Data_Structures_13;

import java.util.Stack;

public class Score_Of_Paranthesis {

	public static void main(String[] args) {
		

		String s1 = "(()(()))";
		System.out.println(score(s1));
	}

	//TC - O(n)
	//SC - O(n)
	private static int score(String s1) {
		
		Stack<String> s = new Stack<>();
		
		int ans = 0;
		
		for(int i = 0; i < s1.length(); i++) {
			
			if(s1.charAt(i) == '(') {
				s.push("(");
			}else {
				
				if(s.peek() == "(") {
					s.pop();
					s.add("1");
				}else {
					
					int c = 0;
					
					while(s.peek() != "(") {
						
						c += Integer.parseInt(s.peek());
						s.pop();
					}
					
					s.pop();
					
					s.push(String.valueOf(2* c));
				}
			}
			
			
		}
		
		while(!s.isEmpty()) {
			
			ans += Integer.parseInt(s.peek());
			s.pop();
		}

		return ans;
	}

}
