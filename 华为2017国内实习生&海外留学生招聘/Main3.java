package org.tinylcy.huawei;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

/**
 * Created by chenyangli. 
 * <p>
 * 背景: 老王从城市5起飞,前往城市X,且城市Y有可能起雾,若城市起雾,那么既不能
 * 从该城市起飞,亦不能到达该城市,求最短距离和相应的最短路径.
 * <p>
 * 一共有6个城市,编号为1至6.
 * 若最终不可达,输出1000,路径为[].
 *
 */
public class Main {

    public static int[][] maze = {
            {-1, -1, -1, -1, -1, -1, -1},
            {-1, 0, 2, 10, 5, 3, -1},
            {-1, -1, 0, 12, -1, -1, 10},
            {-1, -1, -1, 0, -1, 7, -1},
            {-1, 2, -1, -1, 0, 2, -1},
            {-1, 4, -1, -1, 1, 0, -1},
            {-1, 3, -1, 1, -1, 2, 0}};

    public static int minDis = Integer.MAX_VALUE;
    public static ArrayList<Integer> result = null;

    public static void main(String[] args) {
        Main main = new Main();
        Scanner scanner = new Scanner(System.in);
        int X = 0, Y = 0;
        while (scanner.hasNext()) {
            X = scanner.nextInt();
            Y = scanner.nextInt();

            Stack<Integer> path = new Stack<Integer>();
            boolean[] visited = new boolean[7];
            main.initVisited(visited);

            visited[5] = true;
            path.push(5);
            main.dfs(path, visited, 5, 0, X, Y);
            if (result == null) {
                System.out.println(1000);
                System.out.println(new ArrayList<Integer>());
            } else {
                System.out.println(minDis);
                System.out.println(result);
            }

            minDis = Integer.MAX_VALUE;
            result = null;
        }
    }

    private void dfs(Stack<Integer> path, boolean[] visited, int currentCity, int distance, int target, int forbidden) {
        if (currentCity == target) {
            if (distance < minDis) {
                minDis = distance;
                result = new ArrayList<Integer>();
                for (int i = 0; i < path.size(); i++) {
                    result.add(path.get(i));
                }
            }
            return;
        }

        for (int i = 1; i <= 6; i++) {
            if (visited[i]) {
                continue;
            }
            if (maze[currentCity][i] == -1) {
                continue;
            }
            if (currentCity == forbidden || i == forbidden) {
                continue;
            }

            path.push(i);
            visited[i] = true;
            dfs(path, visited, i, distance + maze[currentCity][i], target, forbidden);
            visited[i] = false;
            path.pop();
        }
    }

    private void initVisited(boolean[] visited) {
        for (int i = 0; i < visited.length; i++) {
            visited[i] = false;
        }
    }
}
