/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string. 
 */

package CountAndSay;

public class Solution {

	public String generateSequence(String seq) {
		if (seq.length() == 1) {
			return "1" + seq;
		}
		String result = "";
		int count = 1;
		char key = seq.charAt(0);
		for (int i = 1; i < seq.length(); i++) {
			char ch = seq.charAt(i);
			if (ch == key) {
				count++;
			} else {
				result += (String.valueOf(count) + key);
				count = 1;
				key = ch;
			}
			if (i == seq.length() - 1) {
				result += (String.valueOf(count) + key);
			}
		}
		return result;
	}

	public String countAndSay(int n) {
		String result = "1";
		int index = 1;
		while (index < n) {
			result = generateSequence(result);
			index++;
		}
		return result;
	}

	public static void main(String[] args) {
		Solution object = new Solution();
		System.out.println(object.countAndSay(20));
	}
	
}
