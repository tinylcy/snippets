package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 编写一个函数，确定需要改变几个位，才能将整数A转变成整数B。
 * 给定两个整数int A，int B。请返回需要改变的数位个数。
 *
 * 测试样例：
 * 10,5
 * 返回：4
 */
public class Transform {

    public static int calcCost(int A, int B) {
        return countNumOf1(A ^ B);
    }

    private static int countNumOf1(int x) {
        int count = 0;
        while (x != 0) {
            x = x & (x - 1);
            count++;
        }
        return count;
    }

    public static void main(String [] args) {
        System.out.println(calcCost(10, 5));
    }
}
