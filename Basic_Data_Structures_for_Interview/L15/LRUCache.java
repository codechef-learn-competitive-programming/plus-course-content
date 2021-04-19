package Basic_Data_Structures_Batch_2_Class_15;

import java.util.Deque;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;

public class LRUCache {

	Deque<Integer> deq;
	HashSet<Integer> hashSet;

	int capacity = 3;

	public LRUCache() {

		deq = new LinkedList<>();
		hashSet = new HashSet<>();
	}

	void referMemory(int val) {

		if (!hashSet.contains(val)) {
			if (deq.size() == capacity) {

				int removeVal = deq.removeLast();
				hashSet.remove(removeVal);
			} else {
				deq.remove(val);
			}
		}
		if (hashSet.contains(val)) {
			deq.remove(val);
			deq.push(val);
			return;
		}
		deq.push(val);
		hashSet.add(val);

	}

	void display() {
		Iterator<Integer> itr = deq.iterator();

		while (itr.hasNext()) {
			System.out.print(itr.next() + " ");
		}

		System.out.println();
	}

	public static void main(String[] args) {

		LRUCache c = new LRUCache();
		c.referMemory(1);
		c.referMemory(2);
		c.referMemory(3);
		c.display();
		c.referMemory(4);
		c.display();
		c.referMemory(3);
		c.display();

		c.referMemory(5);
		c.display();
	}

}
