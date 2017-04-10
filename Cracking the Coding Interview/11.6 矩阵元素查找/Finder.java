package cracking_the_coding_interview;

import java.util.Arrays;

/**
 * Created by chenyang li.
 * <p/>
 * 有一个NxM的整数矩阵，矩阵的行和列都是从小到大有序的。请设计一个高效的查找算法，查找矩阵中元素x的位置。
 * 给定一个int有序矩阵mat，同时给定矩阵的大小n和m以及需要查找的元素x，请返回一个二元数组，代表该元素的行号和列号(均从零开始)。保证元素互异。
 * 测试样例：
 * [[1,2,3],[4,5,6]],2,3,6
 * 返回：[1,2]
 */
public class Finder {

    public int[] findElement(int[][] mat, int n, int m, int x) {
        int i = 0, j = m - 1;
        int[] location = {-1, -1};
        while (i >= 0 && i < n && j >= 0 && j < m) {
            if (mat[i][j] == x) {
                location[0] = i;
                location[1] = j;
                return location;
            } else if (mat[i][j] < x) {
                i++;
            } else {
                j--;
            }
        }
        return location;
    }

    public static void main(String[] args) {
        Finder finder = new Finder();
        int[][] mat = {{1, 2, 3}, {4, 5, 6}};
        System.out.println(Arrays.toString(finder.findElement(mat, 2, 3, 6)));
    }
}
