package Basic_Data_Structures_Batch_2_Class_3;

import java.util.Stack;

public class QueueUsingStack {

	Stack<Integer> s1 = new Stack<>();
	Stack<Integer> s2 = new Stack<>();

	void enqueue(int x) {

		// moving elements of s1 to s2
		while (!s1.isEmpty()) {
			s2.push(s1.pop());
		}

		s1.push(x);

		while (!s2.isEmpty()) {

			int val = s2.pop();
			s1.push(val);
		}
	}
	
	int dequeue() {
		
		return s1.pop();
	}
	
	public static void main(String[] args) {
		
		QueueUsingStack queue = new QueueUsingStack();
		queue.enqueue(10);
		queue.enqueue(20);
		queue.enqueue(30);
		
		System.out.println(queue.dequeue());
		System.out.println(queue.dequeue());
	}

}
