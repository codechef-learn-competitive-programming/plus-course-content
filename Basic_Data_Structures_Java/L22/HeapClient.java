package Basic_Data_Structures_21;

import java.util.PriorityQueue;
import java.util.concurrent.PriorityBlockingQueue;

public class HeapClient {

	public static void main(String[] args) {
		
		Heap p = new Heap();
		p.add(100);
		p.add(25);
		p.add(80);
		p.add(40);
		p.add(50);
		
		p.display();
		System.out.println(p.remove());
		p.display();
		System.out.println(p.remove());
		p.display();
		System.out.println(p.remove());
		p.display();
		System.out.println(p.remove());
		p.display();
		System.out.println(p.remove());
		
		PriorityQueue<Integer> pNew = new PriorityQueue<>();
		pNew.add(20);
	    pNew.remove();
	    pNew.clear();
	    

	}

}
