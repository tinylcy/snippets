package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
 * 给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
 * <p/>
 * 测试样例：
 * 0.625
 * 返回：0.101
 */
public class BinDecimal {

    public static String printBin(double num) {
        StringBuilder result = new StringBuilder();
        result.append("0.");
        int count = 32;
        while (count > 0) {
            double temp = num * 2;
            if (temp == 1) {
                result.append(String.valueOf(1));
                break;
            } else if (temp > 1) {
                result.append(String.valueOf(1));
                num = temp - 1;
            } else {
                result.append(String.valueOf(0));
                num = temp;
            }
            count--;
        }
        if (count == 0) {
            return "Error";
        }
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(printBin(0.625355));
    }
}
