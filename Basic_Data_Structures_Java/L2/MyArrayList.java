package Basic_Data_Structures_2;

public class MyArrayList {

	private static final int size_factor = 1;
	private int data[];
	private int index;

	private int size;

	public MyArrayList() {

		this.data = new int[size_factor];
		this.size = size_factor;
	}

	public void add(int val) {

		if (index == this.size - 1) {

			increaseArrayList();

		}

		data[this.index] = val;
		this.index++;
	}

	public int get(int i) {

		if (i > this.index - 1 || i < 0) {

			return -1;

		}

		return this.data[i];
	}

	public void increaseArrayList() {

		int[] newArr = new int[this.size * 2];

		// copy the old values to new array
		for (int i = 0; i < data.length; i++) {
			newArr[i] = data[i];
		}

		this.data = newArr;

	}

	public void remove(int i) {

		if (i > this.index - 1) {
			return;
		}

		if (i < 0) {
			return;
		}

		for (int x = i; x < this.data.length - 1; x++) {
			data[x] = data[x + 1];
		}

		this.index--;
	}

	public static void main(String[] args) {
		
		
		MyArrayList ml = new MyArrayList();
		
		ml.add(0);
		ml.add(12);
		ml.remove(0);
		
		System.out.println(ml.get(0));
		

	}

}
