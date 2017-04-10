package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 */
public class Main {

    static class ListNode {
        int value;
        ListNode next;

        ListNode(int value, ListNode next) {
            this.value = value;
            this.next = next;
        }
    }

    public static ListNode find(ListNode head) {
        if (head == null) {
            return null;
        }

        // 找出任意一个环中的节点
        ListNode fast = head, slow = fast.next;
        while (fast != slow) {
            fast = fast.next.next;
            slow = slow.next;
        }

        // 求出环的长度
        int circleLength = 1;
        fast = fast.next;
        while (fast != slow) {
            fast = fast.next;
            circleLength++;
        }

        slow = fast = head;
        int count = circleLength;
        while (count-- > 1) {
            fast = fast.next;
        }
        while (fast.next != slow) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }


    public static void main(String[] args) {
        ListNode node5 = new ListNode(5, null);
        ListNode node4 = new ListNode(4, node5);
        ListNode node3 = new ListNode(3, node4);
        ListNode node2 = new ListNode(2, node3);
        ListNode node1 = new ListNode(1, node2);
        node5.next = node2;

        ListNode result = find(node1);
        System.out.println(result.value);
    }
}
