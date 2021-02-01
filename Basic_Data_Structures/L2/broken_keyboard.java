import java.util.*;

/**
 * broken_keyboard
 */
public class broken_keyboard {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		String s = in.next();
		int ok[] = new int[26];
		while (k-- > 0) {
			char ch = in.next().charAt(0);
			ok[ch - 'a'] = 1;
		}

		Vector<Integer> v = new Vector<Integer>();
		v.add(-1);
		for (int i = 0; i < n; ++i) {
			if (ok[s.charAt(i) - 'a'] == 0)
				v.add(i);
		}
		v.add(n);
		int ans = 0;

		for (int i = 0; i + 1 < v.size(); ++i) {
			int c = v.get(i + 1) - v.get(i) - 1;
			ans += (c * (c + 1)) / 2;
		}

		System.out.print(ans);
		in.close();
	}

}