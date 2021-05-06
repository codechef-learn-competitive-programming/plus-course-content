package String_Algorithms;

import java.util.ArrayList;
import java.util.List;

public class ZAlgorithm {

	public static void main(String[] args) {

		
		String text = "aaabcxyzaaaabczaaczabbaaaaaaabc";
		String pattern = "aaabc";

		// result will contain the indexes where the match of the pattern is found
		List<Integer> result = patternMatching(text.toCharArray(), pattern.toCharArray());

		for (int val : result) {
			System.out.println(val);
		}

	}

	//TC - (length of pattern + length of text)
	private static List<Integer> patternMatching(char[] text, char[] pattern) {

		char newArr[] = new char[text.length + 1 + pattern.length + 1];

		int i = 0;

		// concatenation

		// adding pattern first to the new char array
		for (char ch : pattern) {
			newArr[i] = ch;
			i++;	
		}

		newArr[i] = '$';
		i++;

		for (char ch : text) {
			newArr[i] = ch;
			i++;
		}

		List<Integer> result = new ArrayList<>();

		int Z[] = calculateZ(newArr);

		for (i = 0; i < Z.length; i++) {
			
			if (Z[i] == pattern.length) {
				
				result.add(i - pattern.length - 1);
			}

		}

		return result;
	}

	//TC - (length of pattern + length of text)
	private static int[] calculateZ(char[] input) {

		int Z[] = new int[input.length];

		int left = 0;
		int right = 0;

		Z[0] = 0;

		// iterating over each and every element in the array to calculate its z-value
		for (int k = 1; k < input.length; k++) {
			//System.out.println(Z[k - 1]);
			// There are two possible cases:
			// 1. k can be out of z-box i.e., greater than the right boundary

			if (k > right) {

				// possibly the starting of the z-box
				left = right = k;
				// trying to match the char at the right index with the prefix of the string
				while (right < input.length && input[right] == input[right - left]) {

					// moving the right boundary
					right++;
				}

				// find the length of z-box
				Z[k] = right - left;
				right--;

			} else {

				// 2. k can be in the box
				// we are operating inside the z-box

				// tells how far are you from the left boundary
				// also the character from the from the start of the string from where
				// you eill copy the z-value
				int k1 = k - left;

				// if the value does not stretch till the right boundary,
				// then simply copy the value
				if (Z[k1] < right - k + 1) {
					Z[k] = Z[k1];
				} else {

					// calculate the z-value for that char instead of copying

					left = k;
					while (right < input.length && input[right] == input[right - left]) {

						// moving the right boundary
						right++;
					}

					// find the length of z-box
					Z[k] = right - left;
					right--;

				}
			}
		}

		return Z;

	}

}
