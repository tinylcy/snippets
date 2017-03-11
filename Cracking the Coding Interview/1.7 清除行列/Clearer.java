package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 请编写一个算法，若N阶方阵中某个元素为0，则将其所在的行与列清零。
 * 给定一个N阶方阵int[][](C++中为vector>)mat和矩阵的阶数n，请返回完成操作后的int[][]方阵(C++中为vector>)，保证n小于等于300，矩阵中的元素为int范围内。
 * <p/>
 * 测试样例：
 * [[1,2,3],[0,1,2],[0,0,1]]
 * 返回：[[0,0,3],[0,0,0],[0,0,0]]
 */
public class Clearer {

    public static int[][] clearZero(int[][] mat, int n) {
        boolean[] row = new boolean[n];
        boolean[] column = new boolean[n];
        for (int i = 0; i < n; i++) {
            row[i] = column[i] = false;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || column[j]) {
                    mat[i][j] = 0;
                }
            }
        }

        return mat;
    }

    public static void main(String[] args) {
        int[][] mat = {{1, 2, 3}, {0, 1, 2}, {0, 0, 1}};
        int[][] cleared = clearZero(mat, 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(cleared[i][j] + " ");
            }
            System.out.println();
        }
    }
}
