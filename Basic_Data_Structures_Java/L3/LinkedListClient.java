package Basic_Data_Structures_3;

public class LinkedListClient {

	public static void main(String[] args) {
		

		LinkedListDemo ll = new LinkedListDemo();
		
		ll.addLast(10);
		ll.addLast(20);
		ll.addLast(30);
		ll.addLast(40);
		ll.addLast(50);
		ll.display();
		ll.reverseKNodes(2);
		
		//ll.display();
		
//		ll.addFirst(0);
//		ll.display();
//		
//		ll.addAt(15, 2);
//		ll.display();
//		
//		ll.removeFirst();
//		ll.display();
//		
//		ll.removeLast();
//		ll.display();
//		
//		ll.removeAt(3);
//		ll.display();
//
//		ll.display();
//		ll.reverse();
//		ll.display();
//		System.out.println(ll.findMid());
//		ll.reorderList();
		ll.display();
		
	}

}
