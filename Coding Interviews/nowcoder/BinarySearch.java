package nowcoder;

/**
 * Created by chenyang li.
 * <p/>
 * 对于一个有序数组，我们通常采用二分查找的方式来定位某一元素，请编写二分查找的算法，在数组中查找指定元素。
 * 给定一个整数数组A及它的大小n，同时给定要查找的元素val，请返回它在数组中的位置(从0开始)，若不存在该元素，返回-1。若该元素出现多次，请返回第一次出现的位置。
 * <p/>
 * 测试样例：
 * [1,3,5,7,9],5,3
 * 返回：1
 */
public class BinarySearch {

    public static int getPos(int[] A, int n, int val) {
        int result = -1;
        int pos = binarySearch(A, n, val);
        while (pos != -1) {
            result = pos;
            pos = binarySearch(A, pos, val);
        }
        return result;
    }

    private static int binarySearch(int[] A, int n, int val) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == val) {
                return mid;
            }
            if (A[mid] > val) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }


    public static void main(String[] args) {
        int[] A = {1, 3, 3, 3, 3, 5, 7, 9};
        System.out.println(getPos(A, A.length, 5));
    }

}
