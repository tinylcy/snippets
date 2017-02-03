package algorithm;

/**
 * Created by chenyangli on 17/2/2.
 */
public class TwoNumbersWithSum {

    public static void findTwoNumber(int[] nums, int target) {
        int sum = 0;
        int i = 0, j = nums.length - 1;
        while (i < j) {
            sum = nums[i] + nums[j];
            if (sum == target) {
                System.out.println(nums[i] + ", " + nums[j]);
                return;
            }
            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        System.out.println("not found.");
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 4, 7, 11, 15};
        findTwoNumber(nums, 19);
    }
}
