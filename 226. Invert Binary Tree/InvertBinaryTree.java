package _226_invert_binary_tree;

/**
 * 
 * @author tinylcy
 * 
 * Invert a binary tree.
 *
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * 
 * to
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 *
 *
 */
public class InvertBinaryTree {

	public TreeNode invertTree(TreeNode root) {
		if (root == null) {
			return null;
		}
		TreeNode leftTree = root.left;
		TreeNode rightTree = root.right;
		root.left = rightTree;
		root.right = leftTree;
		root.left = invertTree(root.left);
		root.right = invertTree(root.right);
		return root;
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
