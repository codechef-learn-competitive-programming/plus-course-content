package Basic_Data_Structures_22;

import java.util.ArrayList;
import java.util.PriorityQueue;

public class Merge_K_Sorted_Lists {

	public static void main(String[] args) {
		

		ArrayList<Integer> list1 = new ArrayList<>();
		list1.add(1);
		list1.add(3);
		list1.add(7);
		list1.add(9);
		list1.add(15);
		
		ArrayList<Integer> list2 = new ArrayList<>();
		list2.add(2);
		list2.add(6);
		list2.add(10);
		
		ArrayList<Integer> list3 = new ArrayList<>();
		list3.add(4);
		list3.add(12);
		
		ArrayList<Integer> list4 = new ArrayList<>();
		list4.add(2);
		list4.add(7);
		list4.add(11);
		list4.add(19);
		
		ArrayList<ArrayList<Integer>> list = new ArrayList<>();
		list.add(list1);
		list.add(list2);
		list.add(list3);
		list.add(list4);
		
		System.out.println(merge(list));

		

	}
	
	static class Pair {
		
		int element;
		int listNo;
		int itemNo;
		
		
	}

	private static ArrayList<Integer> merge(ArrayList<ArrayList<Integer>> list) {
		

		ArrayList<Integer> ans = new ArrayList<>();
		
		PriorityQueue<Pair> heap = new PriorityQueue<>();
		
		for(int i = 0; i < list.size(); i++) {
			Pair np = new Pair();
			np.element = list.get(i).get(0);
			np.listNo = i;
			np.itemNo = 0;
			
			heap.add(np);
		}
		
		while(!heap.isEmpty()) {
			
			Pair rp = heap.remove();
			
			ans.add(rp.element);
			
			rp.itemNo++;
			if(rp.itemNo < list.get(rp.listNo).size()) {
				
				rp.element = list.get(rp.listNo).get(rp.itemNo);
				heap.add(rp);
			}
		}
		
		return ans;
	}

}
