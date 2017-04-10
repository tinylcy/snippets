package cracking_the_coding_interview;

import java.util.ArrayList;
import java.util.Stack;

/**
 * Created by chenyang li.
 * <p/>
 * 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 */
public class Solution {

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

    public static ArrayList<ArrayList<Integer>> findPath(TreeNode root, int target) {
        if (root == null) {
            return new ArrayList<ArrayList<Integer>>();
        }
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        Stack<Integer> path = new Stack<Integer>();
        path.push(root.val);
        findPath(root, path, ret, target);
        return ret;
    }

    private static void findPath(TreeNode current, Stack<Integer> path, ArrayList<ArrayList<Integer>> ret, int target) {
        if (current == null) {
            return;
        }
        if (current.left == null && current.right == null) {
            int sum = 0;
            for (int i = 0; i < path.size(); i++) {
                sum += path.get(i);
            }
            if (sum == target) {
                ret.add(new ArrayList<Integer>(path));
            }
            return;
        }

        if (current.left != null) {
            path.push(current.left.val);
            findPath(current.left, path, ret, target);
            path.pop();
        }

        if (current.right != null) {
            path.push(current.right.val);
            findPath(current.right, path, ret, target);
            path.pop();
        }
    }

    public static void main(String [] args) {
        TreeNode node4 = new TreeNode(5, null, null);
        TreeNode node5 = new TreeNode(2, null, null);
        TreeNode node6 = new TreeNode(1, null, null);
        TreeNode node2 = new TreeNode(3, null, node4);
        TreeNode node3 = new TreeNode(7, node5, node6);
        TreeNode node1 = new TreeNode(4, node2, node3);

        ArrayList<ArrayList<Integer>> ret = findPath(node1, 12);
        System.out.println(ret);
    }
}
