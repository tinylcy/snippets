package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。给定一个升序数组，元素值各不相同，编写一个方法，判断在数组A中是否存在魔术索引。请思考一种复杂度优于o(n)的方法。
 * 给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。
 * <p/>
 * 测试样例：
 * [1,2,3,4,5]
 * 返回：false
 */
public class MagicIndex {

    public static boolean findMagicIndex(int[] A, int n) {
        return findMagicIndex(A, 0, n - 1);
    }

    private static boolean findMagicIndex(int[] A, int low, int high) {
        if (low > high) {
            return false;
        }
        int mid = (low + high) / 2;
        if (A[mid] == mid) {
            return true;
        }

        if (A[mid] < mid) {
            return findMagicIndex(A, mid + 1, high);
        }

        return findMagicIndex(A, low, mid - 1);
    }

    public static void main(String[] args) {
        int[] A = {-1, 1, 3, 4, 5};
        System.out.println(findMagicIndex(A, A.length));
    }
}
