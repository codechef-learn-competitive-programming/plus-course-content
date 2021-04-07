package Basic_Data_Structures_15;

import java.util.ArrayList;
import java.util.LinkedList;

public class HashMap<K, V> {

	private class HMNode {

		K key;
		V value;

		public HMNode(K key, V value) {
			this.key = key;
			this.value = value;
		}

		@Override
		public String toString() {
			return this.key + "@" + this.value;
		}
	}

	private LinkedList<HMNode>[] bucketArray;
	private int size;

	public HashMap() {
		this(5);
	}

	public HashMap(int cap) {
		this.bucketArray = new LinkedList[cap];
		this.size = 0;

		
		for (int i = 0; i < bucketArray.length; i++) {
			bucketArray[i] = new LinkedList<HMNode>();
		}
	}

	public void put(K key, V value) {

		int bi = hashFunction(key);

		LinkedList<HMNode> bucket = bucketArray[bi];

		int fi = findInBucket(bucket, key);
		
		if (fi == -1) {
			HMNode nn = new HMNode(key, value);
			this.size++;
			bucket.addLast(nn);
		} else {
			HMNode n = bucket.get(fi);
			n.value = value;
		}

		double threshold = (double) this.size / this.bucketArray.length;
		if (threshold > 2.0) {

			rehash();
		}
	}

	private void rehash() {

		LinkedList<HMNode>[] oba = this.bucketArray;

		this.bucketArray = (LinkedList<HMNode>[]) new LinkedList[2 * oba.length];

		for (int i = 0; i < bucketArray.length; i++) {
			bucketArray[i] = new LinkedList<HMNode>();

		}

		for (int i = 0; i < oba.length; i++) {
			LinkedList<HMNode> bucket = oba[i];
			for (int j = 0; j < bucket.size(); j++) {
				HMNode node = bucket.get(j);
				put(node.key, node.value);
			}
		}
	}

	private int findInBucket(LinkedList<HashMap<K, V>.HMNode> bucket, K ktf) {

		for (int i = 0; i < bucket.size(); i++) {
			HMNode pn = bucket.get(i);
			if (pn.key.equals(ktf)) {
				return i;
			}
		}

		return -1;

	}

	private int hashFunction(K key) {

		int hc = key.hashCode();
		int bi = Math.abs(hc) % bucketArray.length;

		return bi;

	}

	public V get(K key) {

		int bi = hashFunction(key);
		LinkedList<HMNode> bucket = bucketArray[bi];

		int fi = findInBucket(bucket, key);

		if (fi == -1) {
			return null;

		} else {
			return bucket.get(fi).value;
		}
	}

	public void display() {

		System.out.println("---------------------");

		for (int i = 0; i < bucketArray.length; i++) {
			LinkedList<HMNode> bucket = bucketArray[i];
			System.out.print("B" + i + " =>  ");

			for (int j = 0; j < bucket.size(); j++) {

				HMNode node = bucket.get(j);
				System.out.print(node + ", ");
			}

			System.out.println(".");
		}

		System.out.println("---------------------");

	}

	public boolean containsKey(K key) {

		int bi = hashFunction(key);

		LinkedList<HMNode> bucket = bucketArray[bi];

		int fi = findInBucket(bucket, key);

		if (fi == -1) {
			return false;
		} else {
			return true;
		}
	}

	public V remove(K key) {

		int bi = hashFunction(key);
		LinkedList<HMNode> bucket = bucketArray[bi];

		int fi = findInBucket(bucket, key);

		if (fi == -1) {
			return null;
		} else {
			HMNode node = bucket.remove(fi);
			this.size--;
			return node.value;
		}

	}

	public ArrayList<K> keySet() {

		ArrayList<K> keys = new ArrayList<>();

		for (int i = 0; i < bucketArray.length; i++) {

			LinkedList<HMNode> bucket = bucketArray[i];

			for (int j = 0; j < bucket.size(); j++) {
				HMNode node = bucket.get(j);
				keys.add(node.key);
			}
		}

		return keys;
	}

}
