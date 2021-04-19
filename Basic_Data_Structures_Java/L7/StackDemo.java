package Basic_Data_Structures_7;

public class StackDemo {

	int[] data;
	int tos; // top of stack

	public StackDemo() {
		this(5);
	}

	public StackDemo(int cap) {
		this.data = new int[cap];
		this.tos = -1;
	}

	//O(1)
	public void push(int item) throws Exception {

		if (this.size() == this.data.length) {
			throw new Exception("Stack is Full");
		}
		this.tos++;
		this.data[this.tos] = item;
	}

	public int size() {
		return this.tos + 1;
	}

	//O(1)
	public int pop() throws Exception {

		if (this.size() == 0) {
			throw new Exception("Stack is Empty");
		}
		int rv = this.data[this.tos];
		this.data[this.tos] = 0;
		this.tos--;

		return rv;
	}

	public int top() throws Exception {

		if (this.size() == 0) {
			throw new Exception("Stack is Empty");
		}
		int rv = this.data[this.tos];

		return rv;
	}

	public boolean isEmpty() {

		return this.size() == 0;
	}

	public void display() {

		System.out.println("--------------------");
		for (int i = this.tos; i >= 0; i--) {
			System.out.print(this.data[i] + " ");
		}
		System.out.println();
		System.out.println("--------------------");
	}

}
