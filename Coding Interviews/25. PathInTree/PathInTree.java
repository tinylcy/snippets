package algorithm;

import java.util.Iterator;
import java.util.Stack;

/**
 * Created by chenyang li.
 */
public class PathInTree {

    public static void findPath(BinaryTreeNode root, Stack<Integer> stack, int target) {
        if (root == null) {
            return;
        }
        stack.push(root.value);
        if (root.left == null && root.right == null) {
            if (check(stack, target)) {
                print(stack);
            }
        }

        findPath(root.left, stack, target);
        findPath(root.right, stack, target);
        stack.pop();
    }

    private static boolean check(Stack<Integer> stack, int target) {
        Iterator<Integer> iterator = stack.iterator();
        int sum = 0;
        while (iterator.hasNext()) {
            sum += iterator.next();
        }
        return sum == target;
    }

    private static void print(Stack<Integer> stack) {
        Iterator<Integer> iterator = stack.iterator();
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }
        System.out.println();
    }

    private static class BinaryTreeNode {
        int value;
        BinaryTreeNode left;
        BinaryTreeNode right;

        public BinaryTreeNode(int value, BinaryTreeNode left, BinaryTreeNode right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    public static void main(String[] args) {
        BinaryTreeNode node1 = new BinaryTreeNode(4, null, null);
        BinaryTreeNode node2 = new BinaryTreeNode(7, null, null);
        BinaryTreeNode node3 = new BinaryTreeNode(5, node1, node2);
        BinaryTreeNode node4 = new BinaryTreeNode(12, null, null);
        BinaryTreeNode node5 = new BinaryTreeNode(10, node3, node4);

        Stack<Integer> stack = new Stack<Integer>();
        findPath(node5, stack, 22);
    }

}
