package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
 * 给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。
 */
public class Partition {

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

    public static ListNode partition(ListNode pHead, int x) {
        if (pHead == null) {
            return null;
        }
        ListNode bigHead = null, bigTail = null;
        ListNode smallHead = null, smallTail = null;
        ListNode current = pHead;
        while (current != null) {
            if (current.val >= x) {
                if (bigHead == null) {
                    bigHead = bigTail = current;
                } else {
                    bigTail.next = current;
                    bigTail = current;
                }
                current = current.next;
                bigTail.next = null;
            } else {
                if (smallHead == null) {
                    smallHead = smallTail = current;
                } else {
                    smallTail.next = current;
                    smallTail = current;
                }
                current = current.next;
                smallTail.next = null;
            }

        }
        if (smallTail != null) {
            smallTail.next = bigHead;
            return smallHead;
        }
        return bigHead;
    }

    public static void main(String[] args) {
        ListNode node5 = new ListNode(6, null);
        ListNode node4 = new ListNode(1, node5);
        ListNode node3 = new ListNode(4, node4);
        ListNode node2 = new ListNode(5, node3);
        ListNode node1 = new ListNode(7, node2);

        ListNode result = partition(node1, -1);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
