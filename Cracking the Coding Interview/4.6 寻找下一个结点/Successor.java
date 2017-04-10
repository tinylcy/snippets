package cracking_the_coding_interview;

import java.util.ArrayList;

/**
 * Created by chenyang li.
 * <p/>
 * 请设计一个算法，寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
 * 给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后继结点的值。保证结点的值大于等于零小于等于100000且没有重复值，若不存在后继返回-1。
 */
public class Successor {

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

    public static int findSucc(TreeNode root, int p) {
        ArrayList<Integer> sequence = new ArrayList<Integer>();
        inorder(root, sequence);
        int index = sequence.indexOf(p);
        if (index == sequence.size() - 1) {
            return -1;
        }
        return sequence.get(index + 1);
    }

    private static void inorder(TreeNode root, ArrayList<Integer> sequence) {
        if (root == null) {
            return;
        }
        inorder(root.left, sequence);
        sequence.add(root.val);
        inorder(root.right, sequence);

    }

    public static void main(String[] args) {
        TreeNode node4 = new TreeNode(4, null, null);
        TreeNode node5 = new TreeNode(7, null, null);
        TreeNode node6 = new TreeNode(14, null, null);
        TreeNode node7 = new TreeNode(18, null, null);
        TreeNode node2 = new TreeNode(6, node4, node5);
        TreeNode node3 = new TreeNode(15, node6, node7);
        TreeNode node1 = new TreeNode(10, node2, node3);

        int result = findSucc(node1, 7);
        System.out.println("result = " + result);
    }

}
