package cracking_the_coding_interview;

import java.util.Arrays;

/**
 * Created by chenyang li.
 * <p/>
 * 给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串重点空格。
 * 给定一个string stringA和一个string stringB，请返回一个bool，代表两串是否重新排列后可相同。保证两串的长度都小于等于5000。
 * <p/>
 * 测试样例：
 * "This is nowcoder","is This nowcoder"
 * 返回：true
 * "Here you are","Are you here"
 * 返回：false
 */
public class Same {

    public static boolean checkSam(String stringA, String stringB) {
        if (stringA == null || stringB == null || stringA.length() != stringB.length()) {
            return false;
        }

        char[] charsA = stringA.toCharArray();
        char[] charsB = stringB.toCharArray();
        Arrays.sort(charsA);
        Arrays.sort(charsB);

        for (int i = 0; i < charsA.length; i++) {
            if (charsA[i] != charsB[i]) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        String stringA = "This is tinylcy";
        String stringB = "is This tinylcy";
        System.out.println(checkSam(stringA, stringB));
    }
}
