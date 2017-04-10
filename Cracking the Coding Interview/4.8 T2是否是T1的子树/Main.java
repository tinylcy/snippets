package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 */
public class Main {

    static class TreeNode {
        char value;
        TreeNode left;
        TreeNode right;

        TreeNode(char value, TreeNode left, TreeNode right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    public static boolean haveSubTree(TreeNode treeA, TreeNode treeB) {
        if (sameTree(treeA, treeB)) {
            return true;
        }
        if (treeA != null) {
            if (haveSubTree(treeA.left, treeB)) {
                return true;
            }
            return haveSubTree(treeA.right, treeB);
        }
        return false;
    }

    private static boolean sameTree(TreeNode treeA, TreeNode treeB) {
        if (treeA == null && treeB == null) {
            return true;
        }
        if (treeA == null || treeB == null) {
            return false;
        }
        if (treeA.value != treeB.value) {
            return false;
        }
        return sameTree(treeA.left, treeB.left) && sameTree(treeA.right, treeB.right);
    }

    public static void main(String[] args) {
        TreeNode a4 = new TreeNode('c', null, null);
        TreeNode a5 = new TreeNode('a', null, null);
        TreeNode a2 = new TreeNode('b', a4, a5);
        TreeNode a3 = new TreeNode('d', null, null);
        TreeNode a1 = new TreeNode('a', a2, a3);

        TreeNode b2 = new TreeNode('c', null, null);
        TreeNode b3 = new TreeNode('a', null, null);
        TreeNode b1 = new TreeNode('b', b2, b3);

        System.out.println(haveSubTree(a1, b1));
    }
}
