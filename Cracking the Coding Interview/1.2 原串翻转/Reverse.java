package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 请实现一个算法，在不使用额外数据结构和储存空间的情况下，翻转一个给定的字符串(可以使用单个过程变量)。
 * 给定一个string iniString，请返回一个string，为翻转后的字符串。保证字符串的长度小于等于5000。
 * <p/>
 * 测试样例：
 * "This is nowcoder"
 * 返回："redocwon si sihT"
 */
public class Reverse {

    public static String reverseString(String iniString) {
        char[] chars = iniString.toCharArray();
        for (int low = 0, high = chars.length - 1; low < high; low++, high--) {
            char temp = chars[low];
            chars[low] = chars[high];
            chars[high] = temp;
        }
        return new String(chars);
    }

    public static void main(String[] args) {
        String iniString = "This is tinylcy.";
        System.out.println(reverseString(iniString));
    }
}
