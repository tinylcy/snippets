package cracking_the_coding_interview;

import java.util.ArrayList;

/**
 * Created by chenyang li.
 * <p/>
 * 请实现一种数据结构SetOfStacks，由多个栈组成，其中每个栈的大小为size，当前一个栈填满时，新建一个栈。该数据结构应支持与普通栈相同的push和pop操作。
 * 给定一个操作序列int[][2] ope(C++为vector<vector<int>>)，每个操作的第一个数代表操作类型，若为1，则为push操作，后一个数为应push的数字；若为2，则为pop操作，后一个数无意义。
 * 请返回一个int[][](C++为vector<vector<int>>)，为完成所有操作后的SetOfStacks，顺序应为从下到上，默认初始的SetOfStacks为空。保证数据合法。
 */
public class SetOfStacks {

    static class Stacks {
        ArrayList<ArrayList<Integer>> stacks = new ArrayList<ArrayList<Integer>>();
        final int size;

        Stacks(int size) {
            this.size = size;
        }

        void push(int val) {
            if (stacks.size() == 0) {
                ArrayList<Integer> stack = new ArrayList<Integer>();
                stack.add(val);
                stacks.add(stack);
            } else {
                ArrayList<Integer> topStack = stacks.get(stacks.size() - 1);
                if (topStack.size() == size) {
                    ArrayList<Integer> newStack = new ArrayList<Integer>();
                    newStack.add(val);
                    stacks.add(newStack);
                } else {
                    topStack.add(val);
                }
            }
        }

        int pop() {
            if (stacks.size() == 0 || stacks.get(stacks.size() - 1).size() == 0) {
                throw new RuntimeException("empty stack.");
            }

            ArrayList<Integer> topStack = stacks.get(stacks.size() - 1);
            int topVal = topStack.get(topStack.size() - 1);
            topStack.remove(topStack.size() - 1);
            if (topStack.size() == 0) {
                stacks.remove(topStack);
            }
            return topVal;
        }

    }

    public static ArrayList<ArrayList<Integer>> setOfStacks(int[][] ope, int size) {
        Stacks stacks = new Stacks(size);
        for (int i = 0; i < ope.length; i++) {
            if (ope[i][0] == 1) {
                stacks.push(ope[i][1]);
            } else {
                stacks.pop();
            }
        }

        return stacks.stacks;
    }

    public static void main(String[] args) {
        int[][] ope = {{1, 2}, {2, 3}, {1, 4}, {1, 5}, {1, 5}, {1, 5},
                {1, 5}, {1, 5}, {1, 5}, {1, 5}, {1, 5}, {1, 5}, {1, 5},
                {1, 5}, {1, 5}, {1, 5}, {2, 3}, {2, 3}, {2, 3}};
        System.out.println(setOfStacks(ope, 4));
    }
}
