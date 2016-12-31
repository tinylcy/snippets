package algorithm;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by chenyang li.
 */
public class PrintFromTopToBottom {

    private static class BinaryTreeNode {
        int value;
        BinaryTreeNode left;
        BinaryTreeNode right;

        BinaryTreeNode(int value, BinaryTreeNode left, BinaryTreeNode right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    public static void printFromTopToBottom(BinaryTreeNode root) {
        if (root == null) {
            return;
        }
        Queue<BinaryTreeNode> queue = new LinkedList<BinaryTreeNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            BinaryTreeNode node = queue.poll();
            System.out.print(node.value + " ");
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }
    }

    public static void main(String[] args) {
        BinaryTreeNode node1 = new BinaryTreeNode(5, null, null);
        BinaryTreeNode node2 = new BinaryTreeNode(7, null, null);
        BinaryTreeNode node3 = new BinaryTreeNode(9, null, null);
        BinaryTreeNode node4 = new BinaryTreeNode(11, null, null);
        BinaryTreeNode node5 = new BinaryTreeNode(6, node1, node2);
        BinaryTreeNode node6 = new BinaryTreeNode(10, node3, node4);
        BinaryTreeNode node7 = new BinaryTreeNode(8, node5, node6);
        printFromTopToBottom(node7);
    }
}
