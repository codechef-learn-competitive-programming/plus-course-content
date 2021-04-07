package Basic_Data_Structures_15;

import java.util.HashMap;
import java.util.Set;

public class MaxFreqChar {

	public static void main(String[] args) {

		// Given a string, find the max frequency char
		// [aabcsscbadadaaaa] -> a
		// [aggbde] -> g
		// [adc] -> a/d/c

		// Store the frequency of all the elements in the hashmap

		System.out.println(maxFreqChar("aabcsscbadadaaaa"));

	}

	//TC - O(n)
	//SC - O(n)
	private static char maxFreqChar(String string) {

		HashMap<Character, Integer> map = new HashMap<>();

		for (int i = 0; i < string.length(); i++) {
			char ch = string.charAt(i);
			map.put(ch, map.getOrDefault(ch, 0) + 1);
		}

		Set<Character> keyset = map.keySet();
		int maxFreq = Integer.MIN_VALUE;
		char maxChar = ' ';

		for (char key : keyset) {

			if (map.get(key) > maxFreq) {
				maxFreq = map.get(key);
				maxChar = key;

			}
		}

		return maxChar;
	}

}
