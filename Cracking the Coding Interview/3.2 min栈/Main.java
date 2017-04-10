package cracking_the_coding_interview;

import java.util.Stack;

/**
 * Created by chenyang li.
 */
public class Main {

    private static Stack<Integer> stack = new Stack<Integer>();
    private static Stack<Integer> auxiliary = new Stack<Integer>();

    public static void push(int val) {
        if (stack.isEmpty()) {
            stack.push(val);
            auxiliary.push(val);
        } else {
            int min = auxiliary.peek();
            if (val < min) {
                auxiliary.push(val);
            } else {
                auxiliary.push(min);
            }
            stack.push(val);
        }
    }

    public static int pop() {
        if (stack.isEmpty()) {
            throw new RuntimeException("Stack is empty!");
        }
        int ret = stack.pop();
        auxiliary.pop();
        return ret;
    }

    public static int min() {
        if (auxiliary.isEmpty()) {
            throw new RuntimeException("Stack is empty!");
        }
        int ret = auxiliary.peek();
        return ret;
    }

    public static void main(String[] args) {
        int[] sequence = {5, 7, 9, 3, 1, 6, 9, 0, 3, 2};
        for (int i = 0; i < sequence.length; i++) {
            push(sequence[i]);
        }
        System.out.println(auxiliary);
    }
}
