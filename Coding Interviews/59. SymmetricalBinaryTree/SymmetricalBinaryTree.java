package algorithm;

/**
 * Created by chenyang li.
 */
public class SymmetricalBinaryTree {

    public static class TreeNode {
        int value;
        TreeNode left;
        TreeNode right;

        public TreeNode(int value, TreeNode left, TreeNode right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    public static boolean isSymmetrical(TreeNode root) {
        return isSymmetrical(root, root);
    }

    private static boolean isSymmetrical(TreeNode rootA, TreeNode rootB) {
        if (rootA == null && rootB == null) {
            return true;
        }
        if (rootA == null || rootB == null) {
            return false;
        }
        if (rootA.value != rootB.value) {
            return false;
        }

        return isSymmetrical(rootA.left, rootB.right) && isSymmetrical(rootA.right, rootB.left);
    }

    public static void main(String[] args) {
        TreeNode node1 = new TreeNode(5, null, null);
        TreeNode node2 = new TreeNode(6, null, null);
        TreeNode node3 = new TreeNode(6, null, null);
        TreeNode node4 = new TreeNode(5, null, null);
        TreeNode node5 = new TreeNode(6, node1, node2);
        TreeNode node6 = new TreeNode(6, node3, node4);
        TreeNode node7 = new TreeNode(8, node5, node6);

        System.out.println(isSymmetrical(node7));
    }
}
