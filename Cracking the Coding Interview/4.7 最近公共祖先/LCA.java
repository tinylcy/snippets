package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
 * 给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
 * <p/>
 * 测试样例：
 * 2，3
 * 返回：1
 */
public class LCA {

    public static int getLCA(int a, int b) {
        if (a == b) {
            return a;
        }
        if (a == 1 || b == 1) {
            return 1;
        }
        int aLevel = level(a);
        int bLevel = level(b);
        int deepLevel = aLevel, deepVal = a, shallowLevel = bLevel, shallowVal = b;
        if (aLevel < bLevel) {
            deepLevel = bLevel;
            deepVal = b;
            shallowLevel = aLevel;
            shallowVal = a;
        }

        while (deepLevel > shallowLevel) {
            deepVal /= 2;
            deepLevel--;
        }

        while (deepVal != shallowVal) {
            deepVal /= 2;
            shallowVal /= 2;
        }
        return deepVal;
    }

    private static int level(int x) {
        if (x == 1) {
            return 1;
        }
        int v = 1, ret = 1;
        while (v <= x) {
            v = 2 << ret;
            ret++;
        }
        return ret;
    }

    public static void main(String[] args) {
        System.out.println(getLCA(4, 7));
    }
}
