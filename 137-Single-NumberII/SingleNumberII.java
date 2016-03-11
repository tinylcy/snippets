package _137_SingleNumberII;

import java.util.HashMap;
import java.util.Map;

public class SingleNumberII {

	public int singleNumber(int[] nums) {
		Map<Integer, Integer> map = new HashMap<>();
		int N = nums.length;
		for (int i = 0; i < N; i++) {
			if (!map.containsKey(nums[i])) {
				map.put(nums[i], 1);
			} else {
				int count = map.get(nums[i]);
				map.put(nums[i], count + 1);
			}
		}
		int singleNum = 0;
		for (int num : map.keySet()) {
			if (map.get(num) != 3) {
				singleNum = num;
				break;
			}
		}
		return singleNum;
	}

	public static void main(String[] args) {
		int[] nums = { 5, 2, 1, 5, 2, 1, 1, 5 };
		SingleNumberII singleNumberII = new SingleNumberII();
		System.out.println(singleNumberII.singleNumber(nums));
	}
}
