package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。
 * 给定两个正整数int x,int y，请返回机器人的走法数目。保证x＋y小于等于12。
 * <p/>
 * 测试样例：
 * 2,2
 * 返回：2
 */
public class Robot {

    private static int count = 0;

    public static int countWays(int x, int y) {
        count = 0;
        dfs(1, 1, x, y);
        return count;
    }

    private static void dfs(int currentX, int currentY, int x, int y) {
        if (currentX == x && currentY == y) {
            count++;
            return;
        }

        if (currentY + 1 <= y) {
            dfs(currentX, currentY + 1, x, y);
        }
        if (currentX + 1 <= x) {
            dfs(currentX + 1, currentY, x, y);
        }
    }

    public static void main(String[] args) {
        System.out.println(countWays(6, 6));
    }
}
