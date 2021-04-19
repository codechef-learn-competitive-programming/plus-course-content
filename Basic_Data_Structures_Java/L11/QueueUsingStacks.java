package Basic_Data_Structures_11;

import java.util.Queue;
import java.util.Stack;


public class QueueUsingStacks {

	Stack<Integer> s1 = new Stack<>();
	Stack<Integer> s2 = new Stack<>();
	
	void enqueue(int x) {
		
		while(!s1.isEmpty()) {
			s2.push(s1.pop());
		}
		
		s1.push(x);
		
		while(!s2.isEmpty()) {
			s1.push(s2.pop());
		}
		
	}
	
	int dequeue() {
		return s1.pop();
	}
	
	public static void main(String[] args) {
		
		QueueUsingStacks q = new QueueUsingStacks();
		q.enqueue(10);
		q.enqueue(20);
		q.enqueue(30);
		
		System.out.println(q.dequeue());
		System.out.println(q.dequeue());
	}
}
