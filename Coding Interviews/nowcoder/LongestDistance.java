package nowcoder;

/**
 * Created by chenyang li.
 * <p/>
 * 有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。
 * 给定数组A及它的大小n，请返回最大差值。
 *
 * 测试样例：
 * [10,5],2
 * 返回：0
 */
public class LongestDistance {

    public static int getDis(int[] A, int n) {
        if (n <= 0) {
            return -1;
        }
        int min = A[0], max = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] < min) {
                min = A[i];
            }
            if (A[i] - min > max) {
                max = A[i] - min;
            }
        }

        return max;
    }

    public static void main(String[] args) {
        int[] A = {10, 5};
        System.out.println(getDis(A, 2));
    }
}
