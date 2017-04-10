package cracking_the_coding_interview;

import java.util.ArrayList;

/**
 * Created by chenyang li.
 * <p/>
 * 对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
 * 给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
 * <p/>
 * 测试样例：
 * [[1,0,1],[1,-1,-1],[1,-1,0]]
 * 返回：true
 */
public class Board {

    class Elem {
        int x;
        int y;

        Elem(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public boolean checkWon(int[][] board) {
        ArrayList<Elem> elems = new ArrayList<Elem>();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 1) {
                    elems.add(new Elem(i, j));
                }
            }
        }
        if (elems.size() < 3) {
            return false;
        }

        if (elems.size() == 3) {
            return checkThreeElems(elems);
        }
        if (elems.size() > 3) {
            for (int i = 0; i < elems.size(); i++) {
                for (int j = i + 1; j < elems.size(); j++) {
                    if (j == i) {
                        continue;
                    }
                    for (int k = j + 1; k < elems.size(); k++) {
                        if (k == i || k == j) {
                            continue;
                        }
                        ArrayList<Elem> e = new ArrayList<Elem>();
                        e.add(elems.get(i));
                        e.add(elems.get(j));
                        e.add(elems.get(k));
                        if (checkThreeElems(e)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    private boolean checkThreeElems(ArrayList<Elem> elems) {
        return checkThreeElems(elems.get(0).x, elems.get(0).y, elems.get(1).x, elems.get(1).y, elems.get(2).x, elems.get(2).y);
    }

    private boolean checkThreeElems(int x1, int y1, int x2, int y2, int x3, int y3) {
        if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) {
            return true;
        }
        if ((x1 != x2 && x1 != x3 && x2 != x3) && (y1 != y2 && y1 != y3 && y2 != y3)) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Board board = new Board();
        int[][] A = {{1, -1, -1}, {1, 1, 1}, {-1, -1, 1}};
        System.out.println(board.checkWon(A));
    }

}
