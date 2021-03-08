import java.util.Arrays;

public class KthElement {
	public static void main(String[] args) {
		System.out.println(kthElement(new int[] {1, 2, 3, 4, 5}, 3));
		System.out.println(kthElement(new int[] {30, 20, 1, 55, 67, 40}, 5));
	}
	
	public static int kthElement(int[] nums, int k) {
		return kthElement(nums, 0, nums.length - 1, k);
	}
	
	private static int kthElement(int[] nums, int l, int r, int k) {
		while(l < r) {
			int idx = r;
			int j = partition(nums, l, r, idx);
			if(j == k - 1) return nums[j];
			else if(j < k - 1) l = j + 1;
			else r = j - 1;
		}
		return nums[l];
	}

	private static int partition(int[] nums, int l, int r, int idx) {
		int pivot = nums[idx];
		int j = l;
		for(int i = l; i <= r; i++) {
			if(nums[i] < pivot) {
				swap(nums, i, j);
				j++;
			}
		}
		
		swap(nums, r, j);
		return j;
	}
	
	private static void swap(int[] A, int x, int y) {
		int temp = A[x];
		A[x] = A[y];
		A[y] = temp;
	}
}
