package Basic_Data_Structures_Batch_2_Class_8;

import java.util.Stack;

public class Score_Of_Paranthesis {

	public static void main(String[] args) {

		String s = "(()(()))";
		System.out.println(score(s));

	}

	private static int score(String s1) {

		Stack<String> s = new Stack<>();

		int ans = 0;

		for (int i = 0; i < s1.length(); i++) {
			if (s1.charAt(i) == '(') {
				s.push("(");
			} else {

				if (s.peek() == "(") {
					s.pop();
					s.push("1");
				} else {

					int c = 0;
					while (s.peek() != "(") {
						c += Integer.parseInt(s.peek());
						s.pop();
					}

					s.pop();
					s.push(String.valueOf(2 * c));
				}
			}
		}

		while (!s.isEmpty()) {

			ans += Integer.parseInt(s.peek());
			s.pop();
		}

		return ans;
	}

}
