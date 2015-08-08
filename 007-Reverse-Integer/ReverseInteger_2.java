public class Solution {
    public int reverse(int x) {
		int abs = x < 0 ? -x : x;
		long res = 0;
		while (abs > 0) {
			res = res * 10 + abs % 10;
			abs = abs / 10;
		}
		res = x < 0 ? -res : res;
		if (res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) {
			return 0;
		}
		return (int) res;
	}
}
