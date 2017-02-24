package algorithm;

/**
 * Created by chenyang li.
 */
public class NextNodeInBinaryTrees {

    public static class TreeNode {
        char value;
        TreeNode leftChild;
        TreeNode rightChild;
        TreeNode parent;

        public TreeNode(char value, TreeNode leftChild, TreeNode rightChild) {
            this.value = value;
            this.leftChild = leftChild;
            this.rightChild = rightChild;
        }
    }

    public static TreeNode nextTreeNode(TreeNode treeNode) {
        if (treeNode == null) {
            return null;
        }

        if (treeNode.rightChild != null) {
            return leftestTreeNode(treeNode.rightChild);
        }

        TreeNode parent = treeNode.parent;
        if (parent == null) {
            return null; // 没有右子树，且该节点即为根节点
        }

        if (parent.leftChild == treeNode) {
            return parent;
        }

        while (true) {
            TreeNode grandParent = parent.parent;
            if (grandParent == null) {
                return null;
            }
            if (grandParent.leftChild == parent) {
                return grandParent;
            }
            parent = grandParent;
        }
    }

    private static TreeNode leftestTreeNode(TreeNode treeNode) {
        if (treeNode == null) {
            return null;
        }
        if (treeNode.leftChild == null) {
            return treeNode;
        }

        return leftestTreeNode(treeNode.leftChild);
    }

    public static void main(String[] args) {
        TreeNode node1 = new TreeNode('h', null, null);
        TreeNode node2 = new TreeNode('i', null, null);
        TreeNode node3 = new TreeNode('d', null, null);
        TreeNode node4 = new TreeNode('e', node1, node2);
        TreeNode node5 = new TreeNode('f', null, null);
        TreeNode node6 = new TreeNode('g', null, null);
        TreeNode node7 = new TreeNode('b', node3, node4);
        TreeNode node8 = new TreeNode('c', node5, node6);
        TreeNode node9 = new TreeNode('a', node7, node8);
        node1.parent = node2.parent = node4;
        node3.parent = node4.parent = node7;
        node5.parent = node6.parent = node8;
        node7.parent = node8.parent = node9;

        System.out.println("current = " + node1.value + ", next =" + nextTreeNode(node1).value);
        System.out.println("current = " + node2.value + ", next =" + nextTreeNode(node2).value);
        System.out.println("current = " + node3.value + ", next =" + nextTreeNode(node3).value);
        System.out.println("current = " + node4.value + ", next =" + nextTreeNode(node4).value);
        System.out.println("current = " + node5.value + ", next =" + nextTreeNode(node5).value);
        System.out.println("current = " + node6.value + ", next =" + nextTreeNode(node6)); // null，中序遍历的最后一个节点，不存在下一个节点。
        System.out.println("current = " + node7.value + ", next =" + nextTreeNode(node7).value);
        System.out.println("current = " + node8.value + ", next =" + nextTreeNode(node8).value);
        System.out.println("current = " + node9.value + ", next =" + nextTreeNode(node9).value);

    }
}
