package Basic_Data_Structures_11;

public class QueueClient {

	public static void main(String[] args) throws Exception {
		

		QueueDemo q = new QueueDemo();
		
		q.enqueue(10);
		q.enqueue(20);
		q.enqueue(30);
		//System.out.println(q.dequeue());
		q.display();
		q.enqueue(40);
		q.display();
		q.dequeue();
		q.display();
		q.enqueue(50);
		q.display();
		System.out.println(q.isEmpty());
	}

}
