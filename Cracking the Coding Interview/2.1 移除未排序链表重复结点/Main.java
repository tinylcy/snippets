package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 移除未排序链表中的重复节点。
 * <p/>
 * 思路；若不使用额外的存储空间，只能进行重复遍历。
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

    public static ListNode removeDuplicate(ListNode head) {
        if (head == null) {
            return null;
        }

        ListNode current = head;
        while (current != null) {
            ListNode runner = current;
            while (runner.next != null) {
                if (runner.next.value == current.value) {
                    runner.next = runner.next.next;
                } else {
                    runner = runner.next;
                }
            }
            current = current.next;
        }

        return head;
    }

    public static void main(String[] args) {
        ListNode node5 = new ListNode(1, null);
        ListNode node4 = new ListNode(5, node5);
        ListNode node3 = new ListNode(2, node4);
        ListNode node2 = new ListNode(1, node3);
        ListNode node1 = new ListNode(2, node2);

        ListNode result = removeDuplicate(node1);
        while (result != null) {
            System.out.print(result.value + " ");
            result = result.next;
        }
        System.out.println();
    }
}
