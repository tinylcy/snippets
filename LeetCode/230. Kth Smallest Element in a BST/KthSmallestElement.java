package _230_kth_smallest_element_in_a_BST;

/**
 * 
 * @author tinylcy
 * 
 *         Given a binary search tree, write a function kthSmallest to find the
 *         kth smallest element in it.
 * 
 *         Note: You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 */

public class KthSmallestElement {

	public int kthSmallest(TreeNode root, int k) {
		if (root.left == null && root.right == null && k == 1) {
			return root.val;
		}
		int leftSize = countNodes(root.left);
		if (leftSize + 1 == k) {
			return root.val;
		}
		if (leftSize + 1 > k) {
			return kthSmallest(root.left, k);
		}
		return kthSmallest(root.right, k - leftSize - 1);
	}

	public int countNodes(TreeNode root) {
		if (root == null) {
			return 0;
		}
		return 1 + countNodes(root.left) + countNodes(root.right);
	}

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}
	}
}
