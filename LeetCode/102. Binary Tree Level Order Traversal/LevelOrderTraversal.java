package _102_binary_tree_level_order_traversal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by tinylcy on 2016/3/17.
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *        3
 *       / \
 *      9  20
 *      /   \
 *     15    7
 * return its level order traversal as:
 *   [
 *     [3],
 *     [9,20],
 *     [15,7]
 *   ]
 *
 *   广度优先搜索BFS
 *   用一个LinkedList模拟Queue,用currentLevelCount记录当前层的结点数,用nextLevelCount记录下一层的结点数
 *
 */
public class LevelOrderTraversal {

	public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> lists = new ArrayList<>();
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
				list.add(current.val);
				if (current.left != null) {
					queue.add(current.left);
					++nextLevelCount;
				}
				if (current.right != null) {
					queue.add(current.right);
					++nextLevelCount;
				}
				currentLevelCount--;
			}
			lists.add(list);
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
