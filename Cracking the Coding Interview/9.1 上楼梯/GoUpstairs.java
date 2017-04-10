package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶、3阶。请实现一个方法，计算小孩有多少种上楼的方式。为了防止溢出，请将结果Mod 1000000007
 * 给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100000。
 *
 * 测试样例：
 * 1
 * 返回：1
 */
public class GoUpstairs {

    private static int[] cache = new int[100001];
    private static final int MOD = 1000000007;

    public static int countWays(int n) {
        cache[1] = 1;
        cache[2] = 2;
        cache[3] = 4;

        for (int i = 4; i <= n; i++) {
            cache[i] = ((cache[i - 1] + cache[i - 2]) % MOD + cache[i - 3]) % MOD;
        }

        return cache[n];
    }

    public static void main(String[] args) {
        for (int i = 1; i <= 100; i++) {
            System.out.println(i + ": " + countWays(i));
        }
    }

}
