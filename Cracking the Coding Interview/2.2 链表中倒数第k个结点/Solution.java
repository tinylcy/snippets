package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 输入一个链表，输出该链表中倒数第k个结点。
 */
public class Solution {

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

    public static ListNode FindKthToTail(ListNode head, int k) {
        if (head == null || k <= 0) {
            return null;
        }

        ListNode first = head, second = head;
        int count = k;
        while (--count > 0) {
            first = first.next;
            if (first == null) {
                return null;
            }
        }

        while (first.next != null) {
            first = first.next;
            second = second.next;
        }

        return second;
    }

    public static void main(String[] args) {
        ListNode node5 = new ListNode(5, null);
        ListNode node4 = new ListNode(4, node5);
        ListNode node3 = new ListNode(3, node4);
        ListNode node2 = new ListNode(2, node3);
        ListNode node1 = new ListNode(1, node2);

        System.out.println(FindKthToTail(node1, 4).val);
    }
}
