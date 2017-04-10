package cracking_the_coding_interview;

import java.util.Stack;

/**
 * Created by chenyang li.
 * <p/>
 * 请设计一种算法，解决著名的n皇后问题。这里的n皇后问题指在一个nxn的棋盘上放置n个棋子，使得每行每列和每条对角线上都只有一个棋子，求其摆放的方法数。
 * 给定一个int n，请返回方法数，保证n小于等于10
 * 测试样例：
 * 1
 * 返回：1
 */
public class Queens {

    private static int count = 0;

    public int nQueens(int n) {
        count = 0;
        Stack<Integer> stack = new Stack<Integer>();
        dfs(stack, n);
        return count;
    }

    private void dfs(Stack<Integer> stack, int n) {
        if (stack.size() == n) {
            count++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (check(stack, i)) {
                stack.push(i);
                dfs(stack, n);
                stack.pop();
            }
        }
    }

    private boolean check(Stack<Integer> stack, int location) {
        int locationX = stack.size();
        int locationY = location;
        for (int i = 0; i < stack.size(); i++) {
            int oldX = i;
            int oldY = stack.get(i);
            if (locationY == oldY || abs(locationX - oldX) == abs(locationY - oldY)) {
                return false;
            }
        }
        return true;
    }

    private int abs(int x) {
        return x < 0 ? -x : x;
    }

    public static void main(String[] args) {
        Queens queens = new Queens();
        for (int i = 1; i <= 10; i++) {
            System.out.println(queens.nQueens(i));
        }
    }
}
