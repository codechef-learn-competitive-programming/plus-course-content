package Basic_Data_Structures_7;

import java.util.Stack;

public class StackClient {

	public static void main(String[] args) throws Exception {
		

		StackDemo s = new StackDemo();
		
		s.push(20);
		s.display();
		System.out.println(s.top());
		s.push(30);
		s.display();
		s.pop();
		s.display();
		s.push(40);
		s.display();
		s.push(50);
		s.display();
		s.pop();
		s.display();
		s.push(60);
		s.display();
		System.out.println(s.top());
		
		Stack<Integer> st = new Stack();
		
		st.push(20);
		st.pop();
		
		

	}

}
