package algorithm;

import java.util.Stack;

/**
 * Created by chenyang li.
 */
public class MinStack {

    private Stack<Integer> stack = new Stack<Integer>();
    private Stack<Integer> auxiliary = new Stack<Integer>(); //辅助栈，用于存储每次push/pop栈时的最小值

    public void push(int x) {
        if (stack.empty()) {
            stack.push(x);
            auxiliary.push(x);
        } else {
            stack.push(x);
            int currentMin = auxiliary.peek();
            if (x < currentMin) {
                auxiliary.push(x);
            } else {
                auxiliary.push(currentMin);
            }
        }
    }

    public int pop() {
        if (stack.empty()) {
            throw new RuntimeException("stack is empty.");
        }
        int top = stack.pop();
        auxiliary.pop();
        return top;
    }

    public int min() {
        if (auxiliary.empty()) {
            throw new RuntimeException("stack is empty.");
        }
        return auxiliary.peek();
    }

}
