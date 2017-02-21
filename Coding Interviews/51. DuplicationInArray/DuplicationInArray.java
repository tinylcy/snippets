package algorithm;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by chenyang li.
 */
public class DuplicationInArray {

    public static int getDuplicateByMap(int[] nums) {
        Map<Integer, Integer> dict = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (dict.containsKey(nums[i])) {
                return nums[i];
            } else {
                dict.put(nums[i], nums[i]);
            }
        }
        throw new RuntimeException("no duplicate num.");
    }

    public static int getDuplicateBetter(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                } else {
                    swap(nums, i, nums[i]);
                }
            }
        }
        throw new RuntimeException("no duplicate num.");
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public static void main(String[] args) {
        int[] nums = {2, 3, 1, 0, 2, 5, 3};
        System.out.println(getDuplicateByMap(nums));
        System.out.println(getDuplicateBetter(nums));
    }
}
