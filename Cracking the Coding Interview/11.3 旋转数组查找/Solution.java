package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 给定一个排序后的数组，包含n个元素，但这个数组已被旋转过很多次。请编写代码找出数组中的某个元素。可以假定数组元素
 * 原先是按从小到大的顺序排列的。
 * <p/>
 * 输入：{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14} 找5
 * 输出：8
 */
public class Solution {

    public static int findPivot(int[] A) {
        int low = 0, high = A.length - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (A[mid] > A[low] && A[mid] > A[high]) {
                low = mid;
            } else if (A[mid] < A[low] && A[mid] < A[high]) {
                high = mid;
            } else {
                int pivot = high;
                for (int i = high; i > low; i--) {
                    if (A[i] < A[i - 1]) {
                        pivot = i;
                        break;
                    }
                }
                return pivot;
            }
            if (low == high - 1) {
                int pivot = A[low] < A[high] ? low : high;
                return pivot;
            }
        }
        return -1;
    }

    public static int binarySearch(int[] A, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target) {
                return mid;
            }
            if (A[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static int find(int[] A, int target) {
        int pivot = findPivot(A);
        int left = binarySearch(A, 0, pivot - 1, target);
        if (left != -1) {
            return left;
        }
        return binarySearch(A, pivot, A.length - 1, target);
    }

    public static void main(String[] args) {
        int[] A = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
        System.out.println(find(A, 5));
        int[] B = {2, 2, 2, 3, 4, 2};
        System.out.println(find(B, 4));
    }
}
