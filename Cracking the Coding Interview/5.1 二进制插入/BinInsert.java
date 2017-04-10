package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,其中二进制的位数从低位数到高位且以0开始。
 * 给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。
 *
 * 测试样例：
 * 1024，19，2，6
 * 返回：1100
 *
 * 1024:10000000000
 * 19:10011
 * 1100:10001001100
 */
public class BinInsert {

    public static int binInsert(int n, int m, int j, int i) {
        for (int index = j; index <= i; index++) {
            n = setBit(n, index, getBit(m, index - j));
        }
        return n;
    }

    private static int getBit(int val, int i) {
        if ((val & (1 << i)) != 0) {
            return 1;
        }
        return 0;
    }

    /**
     * 将 val 的第 i 位设置为 j。
     */
    private static int setBit(int val, int i, int j) {
        if (j == 1) {
            return ((1 << i) | val);
        }
        return ((~(1 << i)) & val);
    }

    public static void main(String[] args) {
        System.out.println(binInsert(1024, 19, 2, 6));
    }
}
