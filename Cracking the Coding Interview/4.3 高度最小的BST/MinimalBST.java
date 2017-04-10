package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 对于一个元素各不相同且按升序排列的有序序列，请编写一个算法，创建一棵高度最小的二叉查找树。
 * 给定一个有序序列int[] vals,请返回创建的二叉查找树的高度。
 */
public class MinimalBST {

    public int buildMinimalBST(int[] vals) {
        return minimalBST(0, vals.length - 1);
    }

    private int minimalBST(int low, int high) {
        if (low > high) {
            return 0;
        }
        if (low == high) {
            return 1;
        }
        int mid = (low + high) / 2;
        int leftMinBST = minimalBST(low, mid - 1);
        int rightMinBST = minimalBST(mid + 1, high);
        return leftMinBST > rightMinBST ? leftMinBST + 1 : rightMinBST + 1;
    }

    public static void main(String[] args) {
        int[] vals = {1, 2, 3, 4, 5, 6, 7, 8};
        System.out.println(new MinimalBST().buildMinimalBST(vals));
    }
}
