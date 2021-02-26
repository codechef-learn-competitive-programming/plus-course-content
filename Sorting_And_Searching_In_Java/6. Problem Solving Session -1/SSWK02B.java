import java.util.*;
import java.io.*;

class SSWK02B {
	public static void main (String[] args) throws java.lang.Exception {
		BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(x.readLine());
		while(T-->0){
			StringTokenizer st = new StringTokenizer(x.readLine());
			int N=Integer.parseInt(st.nextToken());
			int X=Integer.parseInt(st.nextToken());
			int[] W=new int[N];
			st = new StringTokenizer(x.readLine());
			for(int i=0;i<N;i++){
				W[i]=Integer.parseInt(st.nextToken());
			}
			numberOfSacks(W, X, N);			
		}
	}

	//Example: [1, 2, 3, 4, 5]; X = 10; (1, 5), (2, 4), (3,)
	private static void numberOfSacks(int[] W, int X, int N) {
		Arrays.sort(W);
		int i = 0, j = N - 1, res = 0; //i -> light pointer and j is the heavy pointer
		while(i < j) {
			if(W[i] + W[j] <= X) {
				res++;
				i++;
				j--;
			} else {
				//If not possible then heavy element needs to be alone.
				res++;
				j--;
			}
		}
		
		if(i == j) {
			res++;
		}
		
		System.out.println(res);
	}
}