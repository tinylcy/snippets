package algorithm;

/**
 * Created by chenyangli on 17/2/2.
 */
public class ContinuesSequenceWithSum {

    public static void findSequence(int[] nums, int target) {
        if (nums.length <= 1) {
          G  return;
        }
        if (nums.length == 2 && nums[0] + nums[1] != target) {
            return;
        }

        int i = 0, j = 1;

        while (i < j && j < nums.length) {
            int tempSum = sum(nums, i, j);
            if (tempSum == target) {
                printSequence(nums, i, j);
                j++;
            } else if (tempSum < target) {
                j++;
            } else {
                i++;
            }
        }
    }

    private static int sum(int[] nums, int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += nums[i];
        }
        return sum;
    }

    private static void printSequence(int[] nums, int start, int end) {
        for (int i = start; i <= end; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8};
        findSequence(nums, 15);
    }
}
