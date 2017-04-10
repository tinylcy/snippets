package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于树中的任意一个结点，其两颗子树的高度差不超过1。
 * 给定指向树根结点的指针TreeNode* root，请返回一个bool，代表这棵树是否平衡。
 */
public class Balance {

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

    public static boolean isBalance(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (root.left == null && root.right == null) {
            return true;
        }

        int leftDepth = getDepth(root.left);
        int rightDepth = getDepth(root.right);
        if (leftDepth - rightDepth < -1 || leftDepth - rightDepth > 1) {
            return false;
        }

        boolean leftBalance = isBalance(root.left);
        if (!leftBalance) {
            return false;
        }

        return isBalance(root.right);
    }

    private static int getDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 1;
        }
        return max(getDepth(root.left), getDepth(root.right)) + 1;
    }

    private static int max(int x, int y) {
        return x > y ? x : y;
    }

    public static void main(String[] args) {
        TreeNode node4 = new TreeNode(4, null, null);
        TreeNode node2 = new TreeNode(2, node4, null);
        TreeNode node3 = new TreeNode(3, null, null);
        TreeNode node1 = new TreeNode(1, node2, node3);
        System.out.println(isBalance(node1));
    }
}
