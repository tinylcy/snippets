package _113_path_sum_II;

import java.util.ArrayList;
import java.util.List;

/**
 * 
 * @author tinylcy
 * 
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *             5
 *            / \
 *           4   8
 *          /   / \
 *         11  13  4
 *        /  \    / \
 *       7    2  5   1
 * return
 * [
 *  [5,4,11,2],
 *  [5,8,4,5]
 * ]
 *
 */

public class PathSumII {

	public List<List<Integer>> pathSum(TreeNode root, int sum) {
		List<List<Integer>> arr = new ArrayList<List<Integer>>();

		if (root == null) {
			return arr;
		}
		if (root.left == null && root.right == null && root.val != sum) {
			return arr;
		}
		List<Integer> list = new ArrayList<Integer>();
		list.add(root.val);
		pathSum(root, sum - root.val, arr, list);
		return arr;
	}

	public void pathSum(TreeNode root, int sum, List<List<Integer>> arr, List<Integer> list) {
		if (root == null) {
			return;
		}
		if (sum == 0 && root.left == null && root.right == null) {
			arr.add(new ArrayList<Integer>(list));
			return;
		}

		if (root.left != null) {
			list.add(root.left.val);
			pathSum(root.left, sum - root.left.val, arr, list);
			list.remove(list.size() - 1);
		}
		if (root.right != null) {
			list.add(root.right.val);
			pathSum(root.right, sum - root.right.val, arr, list);
			list.remove(list.size() - 1);
		}

	}

	private class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		@SuppressWarnings("unused")
		TreeNode(int x) {
			val = x;
		}
	}
}
