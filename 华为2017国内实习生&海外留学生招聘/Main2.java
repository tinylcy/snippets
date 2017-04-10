package org.tinylcy.huawei;

import java.util.Scanner;

/**
 * Created by chenyangli.
 * <p>
 * 令骰子可以 前+后+左+右+逆时针90度+顺时针90度 旋转
 * 骰子的初始状态为123456,分别代表:左右前后上下面的数字
 * <p>
 * L:向左  R:向右  F:向前  B:向后  A:逆时针  C:顺时针
 * <p>
 * 输入一串动作(如RA),输出相应的状态
 */
public class Main2 {

    public String transform(String old, char op) {
        char[] sequence = old.toCharArray();
        char oldLeft = sequence[0];
        char oldRight = sequence[1];
        char oldFront = sequence[2];
        char oldBack = sequence[3];
        char oldUp = sequence[4];
        char oldDown = sequence[5];
        if (op == 'L') {
            sequence[5] = oldLeft;
            sequence[4] = oldRight;
            sequence[0] = oldUp;
            sequence[1] = oldDown;
        } else if (op == 'R') {
            sequence[4] = oldLeft;
            sequence[5] = oldRight;
            sequence[1] = oldUp;
            sequence[0] = oldDown;
        } else if (op == 'F') {
            sequence[5] = oldFront;
            sequence[4] = oldBack;
            sequence[2] = oldUp;
            sequence[3] = oldDown;
        } else if (op == 'B') {
            sequence[4] = oldFront;
            sequence[5] = oldBack;
            sequence[3] = oldUp;
            sequence[2] = oldDown;
        } else if (op == 'A') {
            sequence[2] = oldLeft;
            sequence[3] = oldRight;
            sequence[1] = oldFront;
            sequence[0] = oldBack;
        } else if (op == 'C') {
            sequence[3] = oldLeft;
            sequence[2] = oldRight;
            sequence[0] = oldFront;
            sequence[1] = oldBack;
        }
        return new String(sequence);
    }

    public static void main(String[] args) {
        String init = "123456";
        Scanner scanner = new Scanner(System.in);
        Main2 main = new Main2();
        while (scanner.hasNext()) {
            init = "123456";
            String ops = scanner.next();
            char[] arr = ops.toCharArray();
            for (int i = 0; i < arr.length; i++) {
                init = main.transform(init, arr[i]);
            }
            System.out.println(init);
        }
    }
}
