package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 请实现一个函数，检查一棵二叉树是否为二叉查找树。
 * 给定树的根结点指针TreeNode* root，请返回一个bool，代表该树是否为二叉查找树。
 */
public class Checker {

    public static class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;
        }

        public TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    private static int oldVal = Integer.MIN_VALUE;

    public static boolean checkBST(TreeNode root) {
        oldVal = Integer.MIN_VALUE;
        return check(root);
    }

    public static boolean check(TreeNode root) {
        if (root == null) {
            return true;
        }

        boolean ret = check(root.left);
        if (!ret) {
            return false;
        }
        if (root.val <= oldVal) {
            return false;
        }
        oldVal = root.val;
        ret = check(root.right);
        if (!ret) {
            return false;
        }

        return true;
    }


    public static void main(String[] args) {
        TreeNode node4 = new TreeNode(4, null, null);
        TreeNode node5 = new TreeNode(11, null, null);
        TreeNode node6 = new TreeNode(14, null, null);
        TreeNode node7 = new TreeNode(18, null, null);
        TreeNode node2 = new TreeNode(6, node4, node5);
        TreeNode node3 = new TreeNode(15, node6, node7);
        TreeNode node1 = new TreeNode(10, node2, node3);

        boolean result = checkBST(node1);
        System.out.println("result = " + result);
    }
}
