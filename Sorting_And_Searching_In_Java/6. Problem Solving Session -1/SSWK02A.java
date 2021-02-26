import java.util.*;
import java.io.*;

class SSWK02A {
	public static void main (String[] args) throws java.lang.Exception {
		BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(x.readLine());
		while(T-->0){
			int n=Integer.parseInt(x.readLine());
			int[] a=new int[n];
			StringTokenizer st = new StringTokenizer(x.readLine());
			for(int i=0;i<n;i++){
				a[i]=Integer.parseInt(st.nextToken());
			}
			
			normalizeCount(a, n);			
		}
	}

	private static void normalizeCount(int[] a, int n) {
		Arrays.sort(a);
		int median = a[n/2]; 
		long res = 0L;
		for(int i = 0; i < n; i++) {
			res += Math.abs(a[i] - median);
		}
		System.out.println(res); 
	}
}