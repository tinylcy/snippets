package algorithm;

/**
 * Created by chenyang li.
 */
public class KthNodeInBST {

    static class TreeNode {
        int value;
        TreeNode left;
        TreeNode right;

        TreeNode(int value, TreeNode left, TreeNode right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    private static int countNumOfTreeNodes(TreeNode treeNode) {
        if (treeNode == null) {
            return 0;
        }

        if (treeNode.left == null && treeNode.right == null) {
            return 1;
        }

        return 1 + countNumOfTreeNodes(treeNode.left) + countNumOfTreeNodes(treeNode.right);
    }

    private static int findRightestNode(TreeNode treeNode) {
        if (treeNode == null) {
            throw new RuntimeException("treeNode can not be null");
        }
        if (treeNode.left == null && treeNode.right == null) {
            return treeNode.value;
        }

        return findRightestNode(treeNode.right);
    }

    public static int kthNode(TreeNode root, int k) {
        if (root == null) {
            throw new RuntimeException("bst can not be a null tree.");
        }

        if (countNumOfTreeNodes(root) == k) {
            return findRightestNode(root);
        }

        int leftCount = countNumOfTreeNodes(root.left);

        if (leftCount == k - 1) {
            return root.value;
        }

        if (leftCount == k) {
            return findRightestNode(root.left);
        }

        if (leftCount > k) {
            return kthNode(root.left, k);
        }

        return kthNode(root.right, k - leftCount - 1);
    }

    public static void main(String[] args) {
        TreeNode node2 = new TreeNode(2, null, null);
        TreeNode node4 = new TreeNode(4, null, null);
        TreeNode node6 = new TreeNode(6, null, null);
        TreeNode node8 = new TreeNode(8, null, null);
        TreeNode node3 = new TreeNode(3, node2, node4);
        TreeNode node7 = new TreeNode(7, node6, node8);
        TreeNode node5 = new TreeNode(5, node3, node7);

        for (int i = 1; i < 8; i++) {
            System.out.println(i + "th node = " + kthNode(node5, i));
        }

    }
}
