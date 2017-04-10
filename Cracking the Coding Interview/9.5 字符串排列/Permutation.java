package cracking_the_coding_interview;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * Created by chenyang li.
 * <p/>
 * 编写一个方法，确定某字符串的所有排列组合。
 * 给定一个string A和一个int n,代表字符串和其长度，请返回所有该字符串字符的排列，保证字符串长度小于等于11且字符串中字符均为大写英文字符，
 * 排列中的字符串按字典序从大到小排序。(不合并重复字符串)
 * <p/>
 * 测试样例：
 * "ABC"
 * 返回：["CBA","CAB","BCA","BAC","ACB","ABC"]
 */
public class Permutation {

    public ArrayList<String> getPermutation(String A) {
        ArrayList<String> result = new ArrayList<String>();
        char[] sequence = A.toCharArray();
        dfs(sequence, 0, sequence.length - 1, result);
        Collections.sort(result, new Comparator<String>() {
            public int compare(String o1, String o2) {
                int cmp = o1.compareTo(o2);
                if (cmp > 0) {
                    return -1;
                } else if (cmp < 0) {
                    return 1;
                } else {
                    return 0;
                }
            }
        });
        return result;
    }

    private void dfs(char[] sequence, int low, int high, ArrayList<String> result) {
        if (low > high) {
            return;
        }
        if (low == high) {
            result.add(new String(sequence));
            return;
        }

        for (int i = low; i <= high; i++) {
            swap(sequence, low, i);
            dfs(sequence, low + 1, high, result);
            swap(sequence, low, i);
        }
    }

    private void swap(char[] sequence, int i, int j) {
        char temp = sequence[i];
        sequence[i] = sequence[j];
        sequence[j] = temp;
    }

    public static void main(String[] args) {
        Permutation permutation = new Permutation();
        ArrayList<String> result = permutation.getPermutation("ABC");
        for (String elem : result) {
            System.out.println(elem);
        }
    }
}
