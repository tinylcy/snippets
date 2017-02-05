package algorithm;

import java.util.Arrays;

/**
 * Created by chenyangli on 17/2/5.
 */
public class ContinousCards {

    public static boolean isContinous(int[] nums) {
        Arrays.sort(nums);

        int i, zeroCount = 0;
        for (i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            }
        }

        i = 0;
        while (i < nums.length) {
            if (nums[i] != 0) {
                break;
            }
            i++;
        }

        int gap = 0;
        for (; i < nums.length - 1; i++) {
            if (nums[i + 1] == nums[i]) { // 存在对子
                return false;
            }
            gap += (nums[i + 1] - nums[i] - 1);
        }

        return zeroCount >= gap;
    }

    public static void main(String[] args) {
        int[] nums = {1, 1, 3, 4, 5};
        System.out.println("isContinous: " + isContinous(nums));
    }
}
