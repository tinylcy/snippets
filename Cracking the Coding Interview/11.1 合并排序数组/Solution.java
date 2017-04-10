package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲容纳 B。
 * 编写一个方法，将 B 合并入 A 并排序。
 */
public class Solution {

    public static void sort(int[] A, int[] B, int lenA, int lenB) {
        int len = lenA + lenB;
        int i = lenA - 1, j = lenB - 1, k = len - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        while (j >= 0) {
            A[k--] = A[j--];
        }
    }

    public static void main(String[] args) {
        int[] A = new int[100];
        A[0] = 1;
        A[1] = 4;
        int[] B = {2, 3, 5, 6};
        sort(A, B, 2, 4);
        for (int i = 0; i < 6; i++) {
            System.out.print(A[i] + " ");
        }
        System.out.println();
    }
}
