package Basic_Data_Structures_21;

import java.util.ArrayList;



public class Heap {

	ArrayList<Integer> data = new ArrayList<>();

	public void add(int item) {
		this.data.add(item);
		upheapify(this.data.size() - 1);
	}

	public void display() {
		System.out.println(data);
	}
	private void upheapify(int ci) {

		int pi = (ci - 1) / 2;
		if (this.data.get(pi) > this.data.get(ci)) {
			swap(pi, ci);
			upheapify(pi);
		}

	}

	private void swap(int i, int j) {

		int ith = this.data.get(i);
		int jth = this.data.get(j);

		this.data.set(i, jth);
		this.data.set(j, ith);

	}

	public int remove() {

		if (data.size() == 0) {
			throw new RuntimeException("Heap is Empty");
		}
		
		swap(0, data.size() - 1);
		int rv = data.remove(this.data.size() - 1);
		
		downheapify(0);
		return rv;
	}

	private void downheapify(int pi) {
		
		int mini = pi;
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		
		if(lci < data.size() && data.get(lci) < data.get(mini)) {
			mini = lci;
		}
		
		if(rci < data.size() && data.get(rci) < data.get(mini)) {
			mini = rci;
		}
		
		if(mini != pi) {
			swap(mini, pi);
			downheapify(mini);
		}
		
		
	}
}
