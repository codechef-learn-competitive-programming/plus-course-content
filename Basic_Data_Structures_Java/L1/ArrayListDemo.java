package Basic_Data_Structures_1;

import java.util.ArrayList;

public class ArrayListDemo {

	public static void main(String[] args) {
		

		ArrayList<Integer> list = new ArrayList<>();
		
		System.out.println(list);
		
		//add
		list.add(10);
		list.add(20);
		list.add(30);
		list.add(40);
		
		
		System.out.println(list);
		
		list.add(2, 50);
		System.out.println(list);
		
		System.out.println(list.get(2));
		System.out.println(list.get(3));
		
		list.set(3, 70);
		System.out.println(list);
		
		list.remove(2);
		System.out.println(list);

	}

}
