package nowcoder;

/**
 * Created by chenyang li.
 * <p/>
 * 对于一个字符串，请设计一个高效算法，找到第一次重复出现的字符。
 * 给定一个字符串(不一定全为字母)A及它的长度n。请返回第一个重复出现的字符。保证字符串中有重复字符，字符串的长度小于等于500。
 * <p/>
 * 测试样例：
 * "qywyer23tdd",11
 * 返回：y
 */
public class FirstRepeat {

    public static char findFirstRepeat(String A, int n) {
        boolean[] hash = new boolean[256];
        for (int i = 0; i < 256; i++) {
            hash[i] = false;
        }

        char[] chars = A.toCharArray();
        for (int i = 0; i < n; i++) {
            if (hash[chars[i]]) {
                return chars[i];
            } else {
                hash[chars[i]] = true;
            }
        }

        throw new RuntimeException("not found.");
    }

    public static void main(String [] args) {
        System.out.println(findFirstRepeat("qywyer23tdd", 11));
    }
}
