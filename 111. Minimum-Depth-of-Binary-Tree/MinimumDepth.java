package _111_minimum_depth_of_binary_tree;

/**
 * 
 * @author tinylcy
 * 
 *         Given a binary tree, find its minimum depth.
 * 
 *         The minimum depth is the number of nodes along the shortest path from
 *         the root node down to the nearest leaf node.
 *         
 *         注意：如果只有一个根结点，返回1。如果根结点存在左子树但是不存在右子树，应该返回2.
 *
 */

public class MinimumDepth {

	public int minDepth(TreeNode root) {
		if (root == null) {
			return 0;
		}
		if (root.left == null) {
			return 1 + minDepth(root.right);
		}
		if (root.right == null) {
			return 1 + minDepth(root.left);
		}
		int leftDepth = minDepth(root.left);
		int rightDepth = minDepth(root.right);
		return leftDepth < rightDepth ? 1 + leftDepth : 1 + rightDepth;
	}

	private class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}
	}

}
