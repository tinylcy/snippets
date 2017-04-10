package org.tinylcy.huawei;

import java.util.Scanner;

/**
 * Created by chenyangli.
 * <p>
 * 求两个数的逆序和.
 * 如:
 * 输入:123,456
 * 输出:975
 * 因为 321+654 = 975
 * 输入:100,200
 * 输出:3
 */
public class Main1 {

    int reverse(int a, int b) {
        return transform(a) + transform(b);
    }

    int transform(int x) {
        int ret = 0;
        while (x != 0) {
            int temp = x % 10;
            ret = ret * 10 + temp;
            x = x / 10;
        }
        return ret;
    }

    public static void main(String[] args) {
        Main1 main = new Main1();
        Scanner scanner = new Scanner(System.in);
        int a = 0, b = 0;
        while (scanner.hasNext()) {
            String input = scanner.next();
            String[] tokens = input.split(",");
            a = Integer.parseInt(tokens[0]);
            b = Integer.parseInt(tokens[1]);
            if (!(a >= 0 && a <= 70000 && b >= 0 && b <= 70000)) {
                System.out.println(-1);
            } else {
                System.out.println(main.reverse(a, b));
            }
        }
    }
}
