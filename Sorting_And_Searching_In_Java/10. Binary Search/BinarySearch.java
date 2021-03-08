
public class BinarySearch {
	public static void main(String[] args) {
//		System.out.println(binarySearch(new int[] {10, 20, 30, 40, 50}, 20));
//		System.out.println(binarySearch(new int[] {10, 20, 30, 40, 50}, 10));
//		System.out.println(binarySearch(new int[] {10, 20, 30, 40, 50}, 50));
//		System.out.println(binarySearch(new int[] {10, 20, 30, 40}, 30));
		
//		System.out.println(lowerBound(new int[] {1, 2, 3, 4, 4, 5}, 4));
//		System.out.println(lowerBound(new int[] {1, 2, 3, 3, 5}, 4));
//		System.out.println(lowerBound(new int[] {1, 2, 3, 4, 4}, 6));
//		System.out.println(lowerBound(new int[] {1, 2, 3, 4, 4, 5}, 0));
		
		System.out.println(upperBound(new int[] {1, 2, 4, 4, 4, 5, 6}, 4));
		System.out.println(upperBound(new int[] {1, 2, 4, 4, 4, 5, 6}, 8));
	}
	
	public static int binarySearch(int[] A, int X) {
		int l = 0;
		int r = A.length - 1;
		while(l <= r) {
			int mid = l + (r - l)/2; //(l+r)/2
			if(A[mid] == X) return mid;
			else if(A[mid] > X) r = mid - 1;
			else l = mid + 1;
		}
		return -1;
	}
	
	public static int lowerBound(int[] A, int X) {
		int l = 0;
		int r = A.length;
		while(l < r) {
			int mid = l + (r - l)/2;
			if(X <= A[mid]) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
	
	public static int upperBound(int[] A, int X) {
		int l = 0;
		int r = A.length;
		while(l < r) {
			int mid = l + (r - l)/2;
			if(X >= A[mid]) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}
}
