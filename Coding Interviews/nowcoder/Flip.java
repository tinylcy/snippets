package nowcoder;

/**
 * Created by chenyang li.
 * <p/>
 * 在4x4的棋盘上摆满了黑白棋子，黑白两色的位置和数目随机其中左上角坐标为(1,1),右下角坐标为(4,4),现在依次有一些翻转操作，
 * 要对一些给定支点坐标为中心的上下左右四个棋子的颜色进行翻转，请计算出翻转后的棋盘颜色。
 * 给定两个数组A和f,分别为初始棋盘和翻转位置。其中翻转位置共有3个。请返回翻转后的棋盘。
 * <p/>
 * 测试样例：
 * [[0,0,1,1],[1,0,1,0],[0,1,1,0],[0,0,1,0]],[[2,2],[3,3],[4,4]]
 * 返回：[[0,1,1,1],[0,0,1,0],[0,1,1,0],[0,0,1,0]]
 */
public class Flip {

    public static int[][] flipChess(int[][] A, int[][] f) {
        for (int i = 0; i < f.length; i++) {
            flipOne(A, f[i][0] - 1, f[i][1] - 1);
        }
        return A;
    }

    public static void flipOne(int[][] A, int x, int y) {
        if (x - 1 >= 0) { // up
            A[x - 1][y] = A[x - 1][y] == 0 ? 1 : 0;
        }
        if (x + 1 < 4) { // down
            A[x + 1][y] = A[x + 1][y] == 0 ? 1 : 0;
        }
        if (y - 1 >= 0) { // left
            A[x][y - 1] = A[x][y - 1] == 0 ? 1 : 0;
        }
        if (y + 1 < 4) { // right
            A[x][y + 1] = A[x][y + 1] == 0 ? 1 : 0;
        }
    }

    public static void main(String[] args) {
        int[][] A = {{0, 0, 1, 1}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}};
        int[][] f = {{2, 2}, {3, 3}, {4, 4}};
        flipChess(A, f);
        StringBuilder result = new StringBuilder();
        result.append("[");
        for (int i = 0; i < A.length; i++) {
            result.append("[");
            for (int j = 0; j < A[i].length; j++) {
                result.append(String.valueOf(A[i][j]));
                if (j < A[i].length - 1) {
                    result.append(",");
                }
            }
            result.append("]");
            if (i < A.length - 1) {
                result.append(",");
            }
        }
        result.append("]");

        System.out.println(result.toString());
    }
}
