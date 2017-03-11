package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。
 * 给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于500，图像元素小于等于256。
 * <p/>
 * 测试样例：
 * [[1,2,3],[4,5,6],[7,8,9]],3
 * 返回：[[7,4,1],[8,5,2],[9,6,3]]
 */
public class Transform {

    public static int[][] transformImage(int[][] mat, int n) {
        // 转置
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(mat, i, j, j, i);
            }
        }

        // 交换
        for (int i = 0; i < n; i++) {
            for (int low = 0, high = n - 1; low < high; low++, high--) {
                swap(mat, i, low, i, high);
            }
        }

        return mat;
    }

    private static void swap(int[][] mat, int x1, int y1, int x2, int y2) {
        int temp = mat[x1][y1];
        mat[x1][y1] = mat[x2][y2];
        mat[x2][y2] = temp;
    }

    public static void main(String[] args) {
        int[][] mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int[][] transformed = transformImage(mat, 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(transformed[i][j] + " ");
            }
            System.out.println();
        }
    }
}
