package Basic_Data_Structures_8;

import java.util.Stack;

public class Sort_Stack {

	public static void main(String[] args) {
		

		Stack<Integer> s = new Stack<>();
		
		s.push(41);
		s.push(3);
		s.push(32);
		s.push(2);
		s.push(11);
		
		sort(s);
		
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());


	}

	//No decision control statements
	
	private static void sort(Stack<Integer> s) {
		
		if(s.isEmpty()) {
			return;
		}
		
		int x =  s.pop();
		
		sort(s);
		
		insertInSortedOrder(s, x);
	}

	private static void insertInSortedOrder(Stack<Integer> s, int x) {
		

		if(s.isEmpty() || x > s.peek()) {
			
			s.push(x);
			return;
		}
		
		int temp = s.pop();
		insertInSortedOrder(s, x);
		s.push(temp);
	}

}
