package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 */
public class Solution {

    public static int count = 0;
    public static TreeNode root;

    static class TreeNode {
        int value;
        TreeNode left;
        TreeNode right;
        int leftCount;

        TreeNode(int value, TreeNode left, TreeNode right) {
            this.value = value;
            this.left = left;
            this.right = right;
            this.leftCount = 0;
        }
    }

    public static TreeNode insert(TreeNode root, int value) {
        if (root == null) {
            root = new TreeNode(value, null, null);
            return root;
        }
        if (root.value < value) {
            root.right = insert(root.right, value);
        } else {
            root.leftCount++;
            root.left = insert(root.left, value);
        }
        return root;
    }

    public static void inorder(TreeNode root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        System.out.print(root.value + " ");
        inorder(root.right);
    }


    public static void trace(int x) {
        root = insert(root, x);
    }

    public static int getRandOfNumber(int x) {
        if (root == null) {
            return -1;
        }
        count = 0;
        TreeNode node = root;
        while (node != null) {
            if (node.value == x) {
                count += node.leftCount;
                return count;
            }
            if (node.value > x) {
                node = node.left;
            } else {
                count += node.leftCount + 1;
                node = node.right;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] A = {5, 1, 4, 4, 5, 9, 7, 13, 3};
        root = null;
        for (int i = 0; i < A.length; i++) {
            trace(A[i]);
        }
        inorder(root);
        System.out.println();
        System.out.println(getRandOfNumber(1));
        System.out.println(getRandOfNumber(3));
        System.out.println(getRandOfNumber(4));
        System.out.println(getRandOfNumber(13));
    }
}
