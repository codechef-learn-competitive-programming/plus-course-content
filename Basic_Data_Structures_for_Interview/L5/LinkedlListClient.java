package Basic_Data_Structures_Batch_2_Class_5;

public class LinkedlListClient {

	public static void main(String[] args) {
		
		LinkedListDemo ll = new LinkedListDemo();
		
		ll.addFirst(10);
		ll.display();
		ll.addLast(40);
		ll.display();
		ll.addLast(50);
		ll.display();
		ll.addAt(30, 2);
		ll.display();
		ll.addFirst(0);
		ll.display();
		ll.removeLast();
		ll.display();
		ll.reverse();
		ll.display();
		System.out.println(ll.isPalindrome());

	}

}
