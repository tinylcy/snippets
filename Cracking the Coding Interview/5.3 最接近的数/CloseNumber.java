package cracking_the_coding_interview;

import java.util.Arrays;

/**
 * Created by chenyang li.
 * <p/>
 * 有一个正整数，请找出其二进制表示中1的个数相同、且大小最接近的那两个数。(一个略大，一个略小)
 * 给定正整数int x，请返回一个vector，代表所求的两个数（小的在前）。保证答案存在。
 * 测试样例：
 * 2
 * 返回：[1,4]
 */
public class CloseNumber {

    public static int[] getCloseNumber(int x) {
        int[] ret = new int[2];
        int smaller = x;
        int bigger = x;

        while (smaller > 0) {
            smaller -= 1;
            if (countNumOf1(smaller) == countNumOf1(x)) {
                ret[0] = smaller;
                break;
            }
        }

        while (true) {
            bigger += 1;
            if (countNumOf1(bigger) == countNumOf1(x)) {
                ret[1] = bigger;
                break;
            }
        }

        return ret;
    }

    private static int countNumOf1(int x) {
        int count = 0;
        while (x != 0) {
            x = x & (x - 1);
            count++;
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(getCloseNumber(2)));
    }
}
