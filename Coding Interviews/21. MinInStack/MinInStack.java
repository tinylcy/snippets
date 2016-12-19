package algorithm;

import java.util.Random;

/**
 * Created by chenyang li.
 */
public class MinInStack {

    public static void main(String[] args) {
        MinStack stack = new MinStack();
        Random random = new Random();
        for (int i = 0; i < 20; i++) {
            int num = random.nextInt(10);
            if (num % 2 == 0) {
                int top = stack.pop();
                System.out.println("pop " + top);
            }
            stack.push(num);
            System.out.println("push " + num + ", min = " + stack.min());
        }
    }

}

