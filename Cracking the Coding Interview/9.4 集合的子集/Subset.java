package cracking_the_coding_interview;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;

/**
 * Created by chenyang li.
 * <p/>
 * 请编写一个方法，返回某集合的所有非空子集。
 * 给定一个int数组A和数组的大小int n，请返回A的所有非空子集。保证A的元素个数小于等于20，且元素互异。各子集内部从大到小排序,子集之间字典逆序排序，见样例。
 * 测试样例：
 * [123,456,789]
 * 返回：{[789,456,123],[789,456],[789,123],[789],[456 123],[456],[123]}
 */
public class Subset {

    class Elem implements Comparable<Elem> {
        ArrayList<Integer> list;

        Elem(ArrayList<Integer> list) {
            this.list = list;
        }

        public int compareTo(Elem o) {
            StringBuilder elemStr = new StringBuilder();
            StringBuilder otherElemStr = new StringBuilder();
            for (int i = 0; i < list.size(); i++) {
                elemStr.append(String.valueOf(list.get(i)));
            }
            for (int i = 0; i < o.list.size(); i++) {
                otherElemStr.append(o.list.get(i));
            }
            if (elemStr.toString().compareTo(otherElemStr.toString()) > 0) {
                return -1;
            } else if (elemStr.toString().compareTo(otherElemStr.toString()) < 0) {
                return 1;
            }
            return 0;
        }
    }

    public ArrayList<ArrayList<Integer>> getSubsets(int[] A, int n) {
        Stack<Integer> current = new Stack<Integer>();
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        boolean[] visited = new boolean[n];

        for (int len = 1; len <= n; len++) {
            initVisited(visited, n);
            current.clear();
            dfs(A, current, len, visited, result);
        }

        ArrayList<Elem> elems = new ArrayList<Elem>();
        for (int i = 0; i < result.size(); i++) {
            elems.add(new Elem(result.get(i)));
        }

        Collections.sort(elems);

        ArrayList<ArrayList<Integer>> sortedResult = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < elems.size(); i++) {
            sortedResult.add(elems.get(i).list);
        }

        return sortedResult;
    }

    private void initVisited(boolean[] visited, int n) {
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
    }

    private void dfs(int[] A, Stack<Integer> current, int targetLen, boolean[] visited, ArrayList<ArrayList<Integer>> result) {
        if (current.size() == targetLen) {
            result.add(new ArrayList<Integer>(current));
            return;
        }

        for (int i = 0; i < A.length; i++) {
            if (visited[i]) {
                continue;
            }
            // 如果比current栈顶的元素小，就舍弃该元素
            if (!current.isEmpty()) {
                if (A[i] > current.peek()) {
                    continue;
                }
            }
            visited[i] = true;
            current.push(A[i]);
            dfs(A, current, targetLen, visited, result);
            current.pop();
            visited[i] = false;
        }
    }

    public static void main(String[] args) {
        Subset subset = new Subset();
        int[] A = {123, 456, 789};
        ArrayList<ArrayList<Integer>> result = subset.getSubsets(A, A.length);
        for (int i = 0; i < result.size(); i++) {
            System.out.println(result.get(i));
        }
    }
}
