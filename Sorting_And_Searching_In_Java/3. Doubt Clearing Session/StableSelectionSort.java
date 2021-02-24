import java.util.Arrays;

public class StableSelectionSort {
	public static void main(String[] args) {
		stableSelectionSort(new int[] {4, 5, 3, 2, 4, 1});
	}
	
	//O(n*(n + n)) = O(2n^2) = O(n^2)
	public static void stableSelectionSort(int[] A) {
		int n = A.length;
		for (int i = 0; i < n; i++) { //O(n)
			int minIdx = i; 
			//O(n)
            for (int j = i + 1; j < n; j++) { //Selecting min element from unsorted section
                if (A[minIdx] > A[j]) 
                    minIdx = j; 
            }
  
            //Instead of swapping operation, we do a shifting operation.
            int key = A[minIdx]; 
            //O(n)
            while (minIdx > i) { 
                A[minIdx] = A[minIdx - 1]; 
                minIdx--; 
            } 
            
            //Place key in the vacancy created
            A[i] = key; 
        }
		
		System.out.println("Sorted: " + Arrays.toString(A));
	}

}
