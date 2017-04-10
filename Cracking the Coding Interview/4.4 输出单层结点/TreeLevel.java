package cracking_the_coding_interview;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by chenyang li.
 * <p/>
 * 对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。
 * 给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，请返回一个链表ListNode，代表该深度上所有结点的值，
 * 请按树上从左往右的顺序链接，保证深度不超过树的高度，树上结点的值为非负整数且不超过100000。
 */
public class TreeLevel {

    public static class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }

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

    public ListNode getTreeLevel(TreeNode root, int dep) {
        if (root == null || dep <= 0) {
            return null;
        }

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        int preLevelCount = 0, currentLevelCount = 0;
        ListNode head = null, tail = null;

        queue.add(root);
        preLevelCount = 1;
        while (!queue.isEmpty() && dep-- >= 0) {
            while (preLevelCount-- > 0) {
                TreeNode node = queue.poll();
                if (dep == 0) {
                    if (head == null && tail == null) {
                        head = tail = new ListNode(node.val);
                    } else {
                        ListNode newNode = new ListNode(node.val);
                        tail.next = newNode;
                        tail = newNode;
                    }
                }
                if (node.left != null) {
                    queue.add(node.left);
                    currentLevelCount++;
                }
                if (node.right != null) {
                    queue.add(node.right);
                    currentLevelCount++;
                }
            }
            preLevelCount = currentLevelCount;
            currentLevelCount = 0;
        }
        return head;
    }

    public static void main(String[] args) {
        TreeNode node4 = new TreeNode(4, null, null);
        TreeNode node5 = new TreeNode(5, null, null);
        TreeNode node6 = new TreeNode(6, null, null);
        TreeNode node7 = new TreeNode(7, null, null);
        TreeNode node2 = new TreeNode(2, node4, node5);
        TreeNode node3 = new TreeNode(3, node6, node7);
        TreeNode node1 = new TreeNode(1, node2, node3);

        ListNode head = new TreeLevel().getTreeLevel(node1, 3);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

}
