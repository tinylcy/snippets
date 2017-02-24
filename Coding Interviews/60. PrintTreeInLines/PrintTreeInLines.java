package algorithm;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by chenyang li.
 */
public class PrintTreeInLines {

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

    public static void printTreeInLines(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        TreeNode currentLevelLast = null;
        currentLevelLast = root;
        queue.add(currentLevelLast);
        int currentLevelCount = 1;
        int nextLevelCount = 0;
        while (!queue.isEmpty()) {
            TreeNode treeNode = queue.poll();
            currentLevelCount--;
            System.out.print(treeNode.value + " ");
            if (treeNode.left != null) {
                queue.add(treeNode.left);
                nextLevelCount++;
            }
            if (treeNode.right != null) {
                queue.add(treeNode.right);
                nextLevelCount++;
            }
            if (currentLevelCount == 0) {
                System.out.println();
                currentLevelCount = nextLevelCount;
                nextLevelCount = 0;
            }
        }
    }

    public static void main(String[] args) {
        TreeNode node1 = new TreeNode(5, null, null);
        TreeNode node2 = new TreeNode(7, null, null);
        TreeNode node3 = new TreeNode(9, null, null);
        TreeNode node4 = new TreeNode(11, null, null);
        TreeNode node5 = new TreeNode(6, node1, node2);
        TreeNode node6 = new TreeNode(10, node3, node4);
        TreeNode node7 = new TreeNode(8, node5, node6);

        printTreeInLines(node7);
    }
}
