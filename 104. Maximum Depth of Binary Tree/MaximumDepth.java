package _104_maximum_depth_of_binary_tree;

/**
 * 
 * @author tinylcy
 * 
 *         Given a binary tree, find its maximum depth.
 * 
 *         The maximum depth is the number of nodes along the longest path from
 *         the root node down to the farthest leaf node.
 *
 */
public class MaximumDepth {

	public int maxDepth(TreeNode root) {
		if (root == null) {
			return 0;
		}
		if (root.left != null && root.right == null) {
			return 1 + maxDepth(root.left);
		}
		if (root.right != null && root.left == null) {
			return 1 + maxDepth(root.right);
		}
		int leftDepth = maxDepth(root.left);
		int rightDepth = maxDepth(root.right);
		return leftDepth > rightDepth ? 1 + leftDepth : 1 + rightDepth;
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
