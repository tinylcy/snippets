package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
 * 给定带删除的节点，请执行删除操作，若该节点为尾节点，返回false，否则返回true
 */
public class Remove {

    static class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public static boolean removeNode(ListNode pNode) {
        if (pNode.next == null) {
            return false;
        }

        pNode.val = pNode.next.val;
        pNode.next = pNode.next.next;
        return true;
    }

    public static void main(String[] args) {
        ListNode node5 = new ListNode(5, null);
        ListNode node4 = new ListNode(4, node5);
        ListNode node3 = new ListNode(3, node4);
        ListNode node2 = new ListNode(2, node3);
        ListNode node1 = new ListNode(1, node2);

        removeNode(node3);

        ListNode traverse = node1;
        while (traverse != null) {
            System.out.print(traverse.val + " ");
            traverse = traverse.next;
        }
    }
}
