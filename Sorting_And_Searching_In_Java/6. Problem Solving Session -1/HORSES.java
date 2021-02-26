import java.util.*;
import java.io.*;

class HORSES {
	public static void main (String[] args) throws java.lang.Exception {
		BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(x.readLine());
		while(T-->0){
			int N=Integer.parseInt(x.readLine());
			int[] S=new int[N];
			StringTokenizer st = new StringTokenizer(x.readLine());
			for(int i=0;i<N;i++){
				S[i]=Integer.parseInt(st.nextToken());
			}
			minDifference(S, N);			
		}
	}

	//O(n * log n)
	private static void minDifference(int[] S, int N) {
		Arrays.sort(S);
		int min = Integer.MAX_VALUE;
		for(int i = 0; i < N - 1; i++) {
			min = Math.min(min, S[i + 1] - S[i]);
		}
		System.out.println(min);
	}
	
	private static void minDifferenceNaive(int[] S, int N) {
		int min=Integer.MAX_VALUE;
        for (int i = 0; i < N - 1; i++) {
        	for(int j = i + 1; j < N; j++)
            min = Math.min(min, Math.abs(S[i] - S[j]));
        }
        System.out.println(min);
	}
}