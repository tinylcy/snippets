/**
 * @author chenyangli.
 */
public class MoreThanHalfNumber {

    public static int moreThanHalfNum(int[] nums) {
        int current = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (count == 0) {
                current = nums[i];
                count = 1;
            } else {
                if (nums[i] == current) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return current;
    }

    public static void main(String[] args) {
        // 存在出现次数超过数组长度一半的数字
        int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
        System.out.println(moreThanHalfNum(numbers));

        // 出现次数超过数组长度一半的数字都出现在数组的前半部分
        int numbers2[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
        System.out.println(moreThanHalfNum(numbers2));

        // 出现次数超过数组长度一半的数字都出现在数组的后半部分
        int numbers3[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
        System.out.println(moreThanHalfNum(numbers3));
    }
}
