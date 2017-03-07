package algorithm;

import java.util.Stack;

/**
 * Created by chenyang li.
 */
public class PrintTreeInZigzag {

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

    public static void print(TreeNode root) {
        if (root == null) {
            return;
        }
        Stack<TreeNode> stackA = new Stack<TreeNode>();
        Stack<TreeNode> stackB = new Stack<TreeNode>();

        stackA.push(root);
        boolean flag = true;
        while (!stackA.isEmpty() || !stackB.isEmpty()) {
            if (flag) {
                while (!stackA.isEmpty()) {
                    TreeNode node = stackA.pop();
                    System.out.print(node.value + " ");
                    if (node.left != null) {
                        stackB.push(node.left);
                    }
                    if (node.right != null) {
                        stackB.push(node.right);
                    }
                }
                System.out.println();
                flag = !flag;
            } else {
                while (!stackB.isEmpty()) {
                    TreeNode node = stackB.pop();
                    System.out.print(node.value + " ");
                    if (node.right != null) {
                        stackA.push(node.right);
                    }
                    if (node.left != null) {
                        stackA.push(node.left);
                    }
                }
                System.out.println();
                flag = !flag;
            }
        }
    }

    public static void main(String[] args) {
        TreeNode node8 = new TreeNode(8, null, null);
        TreeNode node9 = new TreeNode(9, null, null);
        TreeNode node10 = new TreeNode(10, null, null);
        TreeNode node11 = new TreeNode(11, null, null);
        TreeNode node12 = new TreeNode(12, null, null);
        TreeNode node13 = new TreeNode(13, null, null);
        TreeNode node14 = new TreeNode(14, null, null);
        TreeNode node15 = new TreeNode(15, null, null);
        TreeNode node4 = new TreeNode(4, node8, node9);
        TreeNode node5 = new TreeNode(5, node10, node11);
        TreeNode node6 = new TreeNode(6, node12, node13);
        TreeNode node7 = new TreeNode(7, node14, node15);
        TreeNode node2 = new TreeNode(2, node4, node5);
        TreeNode node3 = new TreeNode(3, node6, node7);
        TreeNode node1 = new TreeNode(1, node2, node3);

        print(node1);
    }
}
