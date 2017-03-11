package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
 * 给定两个字符串s1,s2,请返回bool值代表s2是否由s1旋转而成。字符串中字符为英文字母和空格，区分大小写，字符串长度小于等于1000。
 * <p/>
 * 测试样例：
 * "Hello world","worldhello "
 * 返回：false
 * "waterbottle","erbottlewat"
 * 返回：true
 */
public class ReverseEqual {

    public static boolean checkReverseEqual(String s1, String s2) {
        String s1s1 = s1 + s1;
        return s1s1.contains(s2);
    }

    public static void main(String[] args) {
        String s1 = "Hello world";
        String s2 = "worldhello";
        System.out.println(checkReverseEqual(s1, s2));
    }
}
