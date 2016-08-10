package _107_binary_tree_level_order_traversal_II;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by tinylcy on 2016/3/18.
 *
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values.
 * (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *   /   \
 *  15    7
 * return its bottom-up level order traversal as:
 *   [
 *     [15,7],
 *     [9,20],
 *     [3]
 *   ]
 *
 *   类似于No.102题，还是BFS,用LinkedList来存储每一层，每遍历完一层就将该层插入到LinkedList的头部
 */
public class LevelOrderTraversalII {

	public List<List<Integer>> levelOrderBottom(TreeNode root) {
		LinkedList<List<Integer>> lists = new LinkedList<>();
		if (root == null) {
			return lists;
		}
		LinkedList<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		int currentLevelCount = 1;
		int nextLevelCount = 0;
		while (!queue.isEmpty()) {
			List<Integer> list = new ArrayList<>();
			while (currentLevelCount > 0) {
				TreeNode current = queue.poll();
				if (current.left != null) {
					queue.add(current.left);
					++nextLevelCount;
				}
				if (current.right != null) {
					queue.add(current.right);
					++nextLevelCount;
				}
				--currentLevelCount;
				list.add(current.val);
			}
			lists.addFirst(list);
			currentLevelCount = nextLevelCount;
			nextLevelCount = 0;
		}
		return lists;
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
