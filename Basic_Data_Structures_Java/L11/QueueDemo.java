package Basic_Data_Structures_11;

public class QueueDemo {

	public int[] data;
	public int front;
	public int size;

	public QueueDemo() {
		this(5);
	}

	public QueueDemo(int cap) {
		this.data = new int[cap];
		this.front = 0;
		this.size = 0;

	}

	//O(1)
	public void enqueue(int item) throws Exception {

		if (this.size == this.data.length) {

			throw new Exception("Queue is full");
		}

		int idx = (this.front + this.size) % this.data.length;
		data[idx] = item;
		this.size++;
	}

	//O(1)
	public int dequeue() throws Exception {

		if (this.size == 0) {
			throw new Exception("Queue is empty");
		}

		int rv = this.data[this.front];
		this.data[this.front] = 0;
		this.front = (this.front + 1) % this.data.length;
		this.size--;

		return rv;
	}

	public int getFirst() throws Exception {

		if (this.size == 0) {
			throw new Exception("Queue is empty");
		}

		int rv = this.data[this.front];

		return rv;
	}

	public int size() {
		return this.size;

	}

	public boolean isEmpty() {

		return this.size == 0;
	}

	public void display() {

		System.out.println("---------------------");
		for (int i = 0; i < this.size; i++) {

			int idx = (i + this.front) % this.data.length;

			System.out.print(this.data[idx] + " ");
		}
		System.out.println(".");
		System.out.println("---------------------");
	}
	

}
