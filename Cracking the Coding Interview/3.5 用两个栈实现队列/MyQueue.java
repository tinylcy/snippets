package cracking_the_coding_interview;

import java.util.Stack;

/**
 * Created by chenyang li.
 * <p/>
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 */
public class MyQueue {

    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();

    public void push(int node) {
        stack1.push(node);
    }

    public int pop() {
        if (!stack2.isEmpty()) {
            return stack2.pop();
        }
        if (stack1.isEmpty()) {
            throw new RuntimeException("empty queue.");
        }
        int result = 0;
        while (!stack1.isEmpty()) {
            int top = stack1.pop();
            if (stack1.isEmpty()) {
                result = top;
                break;
            }
            stack2.push(top);
        }
        return result;
    }

    public static void main(String[] args) {
        MyQueue queue = new MyQueue();
        queue.push(1);
        queue.push(2);
        queue.push(3);
        System.out.println(queue.pop());
        queue.push(4);
        System.out.println(queue.pop());
        System.out.println(queue.pop());
        System.out.println(queue.pop());
    }
}
