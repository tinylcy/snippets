package cracking_the_coding_interview;

import java.util.Arrays;

/**
 * Created by chenyang li.
 * <p/>
 * 请实现一个算法，确定一个字符串的所有字符是否全都不同。这里我们要求不允许使用额外的存储结构。
 * 给定一个string iniString，请返回一个bool值,True代表所有字符全都不同，False代表存在相同的字符。保证字符串中的字符为ASCII字符。字符串的长度小于等于3000。
 * <p/>
 * 测试样例：
 * "aeiou"
 * 返回：True
 * "BarackObama"
 * 返回：False
 */
public class Different {

    public static boolean checkDifferent(String iniString) {
        if (iniString == null || iniString.length() == 0) {
            return false;
        }
        if (iniString.length() == 1) {
            return true;
        }

        char[] chars = iniString.toCharArray();
        Arrays.sort(chars);

        char preCurrent = chars[0], current;
        for (int i = 1; i < chars.length; i++) {
            current = chars[i];
            if (current == preCurrent) {
                return false;
            }
            preCurrent = current;
        }
        return true;
    }

    public static void main(String[] args) {
        String iniString = "BarackObama";
        System.out.println(checkDifferent(iniString));
    }
}
