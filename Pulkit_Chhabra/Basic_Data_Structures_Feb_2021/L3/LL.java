import java.util.*;

/**
 * LL
 */
public class LL {
	public static void main(String[] args) {
		LinkedList<Integer> linkedList = new LinkedList<Integer>();

		for (int i = 1; i <= 10; ++i)
			linkedList.add(i);

		System.out.println(linkedList);

		linkedList.removeLast();
		System.out.println(linkedList);

		linkedList.removeFirst();
		System.out.println(linkedList);
	}
}