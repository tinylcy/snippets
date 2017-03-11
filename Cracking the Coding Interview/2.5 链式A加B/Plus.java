package cracking_the_coding_interview;

/**
 * Created by chenyang li.
 * <p/>
 * 有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表的首部。编写函数对这两个整数求和，并用链表形式返回结果。
 * 给定两个链表ListNode* A，ListNode* B，请返回A+B的结果(ListNode*)。
 * <p/>
 * 测试样例：
 * {1,2,3},{3,2,1}
 * 返回：{4,4,4}
 */
public class Plus {

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

    public static ListNode plusAB(ListNode a, ListNode b) {
        if (a == null && b == null) {
            return null;
        }
        if (a == null) {
            return b;
        }
        if (b == null) {
            return a;
        }

        int lenA = getListLength(a);
        int lenB = getListLength(b);
        ListNode answerHead = null, answerTail = null, longer = null, shorter = null;
        if (lenA >= lenB) {
            longer = a;
            shorter = b;
        } else {
            longer = b;
            shorter = a;
        }
        answerHead = longer;

        int sum = 0, carry = 0;
        while (shorter != null) {
            sum = longer.val + shorter.val + carry;
            longer.val = sum % 10;
            carry = sum / 10;
            longer = longer.next;
            shorter = shorter.next;
        }

        while (longer != null) {
            sum = longer.val + carry;
            longer.val = sum % 10;
            carry = sum / 10;
            longer = longer.next;
        }

        if (carry != 0) {
            answerTail = answerHead;
            while (answerTail.next != null) {
                answerTail = answerTail.next;
            }
            ListNode node = new ListNode(carry);
            answerTail.next = node;
        }

        return answerHead;
    }

    private static int getListLength(ListNode head) {
        int len = 0;
        while (head != null) {
            len++;
            head = head.next;
        }
        return len;
    }

    public static void main(String[] args) {
        ListNode a4 = new ListNode(9, null);
        ListNode a3 = new ListNode(9, a4);
        ListNode a2 = new ListNode(9, a3);
        ListNode a1 = new ListNode(9, a2);

        ListNode b3 = new ListNode(8, null);
        ListNode b2 = new ListNode(7, b3);
        ListNode b1 = new ListNode(6, b2);

        ListNode result = plusAB(a1, b1);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
