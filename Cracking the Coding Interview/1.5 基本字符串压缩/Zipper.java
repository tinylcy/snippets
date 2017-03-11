package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
 * 给定一个string iniString为待压缩的串(长度小于等于10000)，保证串内字符均由大小写英文字母组成，返回一个string，为所求的压缩后或未变化的串。
 * <p/>
 * 测试样例
 * "aabcccccaaa"
 * 返回："a2b1c5a3"
 * "welcometonowcoderrrrr"
 * 返回："welcometonowcoderrrrr"
 */
public class Zipper {

    public static String zipString(String iniString) {
        if (iniString == null || iniString.length() == 0) {
            return null;
        }
        if (iniString.length() == 1) {
            return iniString;
        }

        StringBuilder result = new StringBuilder();
        char base = iniString.charAt(0), current = iniString.charAt(1);
        int count = 1;
        for (int i = 1; i < iniString.length(); i++) {
            current = iniString.charAt(i);
            if (current != base) {
                result.append(base).append(count);
                base = current;
                count = 1;
            } else {
                count++;
            }
        }
        result.append(base).append(count);

        return result.toString().length() < iniString.length() ? result.toString() : iniString;
    }

    public static void main(String[] args) {
        System.out.println(zipString("aabcccccaaa"));
        System.out.println(zipString("welcometonowcoderrrrr"));
    }
}
