package String_Algorithms;

public class Rabin_Karp {

	public static void main(String[] args) {

		String text = "aabaabaadaabaaabaa";
		String pat = "aaba";

		int q = 101; // random

		search(pat, text, q);

	}

	private static void search(String pat, String text, int q) {

		int M = pat.length();
		int N = text.length();

		int i, j;
		int d = 256;
		// hash value of pattern
		int p = 0;
		// hash value of text
		int t = 0;
		int h = 1;

		// h -> pow(d, M - 1)%q
		for (i = 0; i < M - 1; i++) {
			h = (h * d) % q;
		}

		// Calculate hash value of pattern
		// Calculate hash value of first window of text
		for (i = 0; i < M; i++) {

			p = (d * p + pat.charAt(i)) % q;
			t = (d * t + text.charAt(i)) % q;
		}

		// slide the pattern over the text window by window

		for (i = 0; i <= N - M; i++) {

			// check the hash value of the current window of text and pattern
			if (p == t) {

				// check for collision
				for (j = 0; j < M; j++) {
					if (text.charAt(i + j) != pat.charAt(j)) {
						break;
					}
				}

				if (j == M) {
					System.out.println(i);
				}
			}

			// Calculate hash value of next window of text
			// remove the first digit and add last one in the end.
			if (i < N - M) {
				t = (d * (t - text.charAt(i) * h) + text.charAt(i + M)) % q;

				if (t < 0) {
					t = (t + q);
				}
			}
		}

	}

}
