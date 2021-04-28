import java.util.*;

/**
 * add_l_to_r
 */
public class add_l_to_r {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int arr[] = new int[n + 1], b[] = new int[n + 2];

		for (int i = 1; i <= n; ++i) {
			arr[i] = in.nextInt();
		}

		int m = in.nextInt();
		while (m-- > 0) {
			int l, r, x;
			l = in.nextInt();
			r = in.nextInt();
			x = in.nextInt();
			b[l] += x;
			b[r + 1] -= x;
		}

		for (int i = 1; i <= n; ++i)
			b[i] += b[i - 1];

		for (int i = 1; i <= n; ++i)
			System.out.printf("%d ", arr[i] + b[i]);

		in.close();
	}
}