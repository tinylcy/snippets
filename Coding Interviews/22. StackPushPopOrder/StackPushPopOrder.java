package algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

/**
 * Created by chenyang li.
 */
public class StackPushPopOrder {

    public static boolean isPopOrder(final ArrayList<Integer> push, final ArrayList<Integer> pop, int n) {
        Stack<Integer> stack = new Stack<Integer>();
        int i = 0, j = 0;
        while (i < n) {
            if (push.get(i) == pop.get(j)) {
                i++;
                j++;
            } else {
                stack.push(push.get(i));
                i++;
            }
        }

        while (!stack.empty()) {
            if (stack.peek() != pop.get(j)) {
                return false;
            } else {
                stack.pop();
                j++;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        ArrayList<Integer> push = new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5));
        ArrayList<Integer> pop1 = new ArrayList<Integer>(Arrays.asList(4, 5, 3, 2, 1));
        ArrayList<Integer> pop2 = new ArrayList<Integer>(Arrays.asList(4, 3, 5, 2, 1));

        System.out.println(isPopOrder(push, pop1, 5));
        System.out.println(isPopOrder(push, pop2, 5));
    }
}
