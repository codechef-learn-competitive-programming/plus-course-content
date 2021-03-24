package Basic_Data_Structures_3;

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

	public void addFirst(int data) {

		Node n = new Node(data);
		n.next = this.head;
		this.head = n;

	}

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

	public int findMid() {

		Node slow = head;
		Node fast = head;

		while (fast != null && fast.next != null) {

			slow = slow.next;
			fast = fast.next.next;
		}

		return slow.data;
	}

	public void reorderList() {

		Node slow = head;
		Node fast = head;

		// 1. Find mid of LinkedList
		while (fast != null && fast.next != null) {

			slow = slow.next;
			fast = fast.next.next;
		}

		// 2. Reverse the second half of LL
		Node prev = null;
		Node curr = slow;
		Node next = null;

		while (curr != null) {

			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;
		}

		// 3. Merge two sorted LinkedList
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

	public int getIntersection(Node head1, Node head2) {

		Node temp = head1;
		int count1 = 0;
		while (temp != null) {
			count1++;
			temp = temp.next;
		}

		temp = head1;
		int count2 = 0;
		while (temp != null) {
			count2++;
			temp = temp.next;
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

	private int intersect(int d, Node head2, Node head1) {
		
		Node curr1 = head1;
		Node curr2 = head2;
		
		for(int i = 0; i < d; i++) {
			if(curr1 == null) {
				return -1;
			}
			
			curr1 = curr1.next;
		}
		
		while(curr1 != null && curr2 != null) {
			
			if(curr1.data == curr2.data) {
				return curr1.data;
			}
			
			curr1 = curr1.next;
			curr2 = curr2.next;
		}
		
		return -1;
	}
	
	public boolean detect_cycle(Node head) {
		
		Node slow = head;
		Node fast = head;
		
		while(slow != null && fast != null && fast.next != null) {
			
			slow = slow.next;
			fast = fast.next.next;
			
			if(slow == fast) {
				return true;
			}
			
		}
		
		return false;
	}

}
