package Basic_Data_Structures_Batch_2_Class_5;

public class LinkedListDemo {

	class Node {

		int data;
		Node next;

		Node(int data) {
			this.data = data;
		}
	}

	Node head;

	public boolean isEmpty() {
		return this.head == null;
	}

	public void display() {

		System.out.println("-----------------------------");
		Node temp = this.head;
		while (temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}

		System.out.println(".");
		System.out.println("-----------------------------");
	}

	// O(1)
	public void addFirst(int data) {

		Node n = new Node(data);
		n.next = this.head;
		this.head = n;

	}

	// O(n)
	public void addLast(int data) {

		if (this.head == null) {
			addFirst(data);
			return;
		}

		Node n = new Node(data);

		Node temp = this.head;

		while (temp.next != null) {

			temp = temp.next;

		}

		temp.next = n;
	}

	// O(n)
	public void addAt(int data, int idx) {

		if (idx < 0) {
			return;
		}

		if (idx == 0) {
			addFirst(data);
			return;
		}

		Node nn = new Node(data);

		Node temp = this.head;

		for (int i = 0; i < idx - 1; i++) {

			temp = temp.next;
		}

		Node forward = temp.next;
		temp.next = nn;
		nn.next = forward;

	}

	// O(1)
	public int removeFirst() {

		if (this.head == null) {
			return -1;
		}

		int rv = this.head.data;

		this.head = this.head.next;

		return rv;
	}

	public int removeLast() {

		Node temp = this.head;

		while (temp.next.next != null) {
			temp = temp.next;
		}

		int rv = temp.next.data;
		temp.next = null;

		return rv;
	}

	public int removeAt(int idx) {

		if (idx < 0) {
			return -1;
		}

		if (idx == 0) {
			return removeFirst();
		}

		Node temp = this.head;
		for (int i = 0; i < idx - 1; i++) {

			temp = temp.next;

		}

		int rv = temp.next.data;
		temp.next = temp.next.next;

		return rv;
	}

	// O(n)
	// Iterative Solution
	public void reverse() {

		Node prev = null;
		Node curr = head;
		Node next = null;

		while (curr != null) {

			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;
		}

		head = prev;
	}

	public boolean detectCycle(Node head) {

		Node slow = head;
		Node fast = head;

		while (slow != null && fast != null && fast.next != null) {

			slow = slow.next;
			fast = fast.next.next;
			if (slow == fast) {
				return true;
			}
		}

		slow = head;

		while (slow != fast) {
			slow = slow.next;
			fast = fast.next;

		}

		return false;
	}

	public int getIntersection(Node head1, Node head2) {

		Node temp = head1;
		int count1 = 0;

		while (temp != null) {
			count1++;
			temp = temp.next;
		}
		temp = head2;
		int count2 = 0;
		while (temp != null) {
			temp = temp.next;
			count2++;
		}
		int d;

		if (count1 > count2) {

			d = count1 - count2;

			return intersect(d, head1, head2);
		} else {
			d = count2 - count1;
			return intersect(d, head2, head1);
		}
	}

	private int intersect(int d, Node head1, Node head2) {

		Node curr1 = head1;
		Node curr2 = head2;

		for (int i = 0; i < d; i++) {
			if (curr1 == null) {
				return -1;
			}
			curr1 = curr1.next;
		}

		while (curr1 != null && curr2 != null) {

			if (curr1.data == curr2.data) {

				return curr1.data;
			}

			curr1 = curr1.next;
			curr2 = curr2.next;

		}

		return -1;
	}

	public void reorderList() {

		Node slow = head;
		Node fast = head;

		
		while (fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;

		}

		Node prev = null;
		Node curr = slow;
		Node next = null;

		while (curr != null) {

			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;
		}

		// Merge
		Node first = head;
		Node second = prev;
		Node temp;

		while (second.next != null) {

			temp = first.next;
			first.next = second;
			first = temp;
			
			temp = second.next;
			second.next = first;
			second = temp;
		}
	}
}
