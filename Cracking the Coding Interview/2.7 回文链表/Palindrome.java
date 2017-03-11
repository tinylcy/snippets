package cracking_the_coding_interview;

import java.util.ArrayList;

/**
 * Created by chenyang li.
 */
public class Palindrome {

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

    public static boolean isPalindrome(ListNode pHead) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        ListNode current = pHead;
        while (current!= null) {
            list.add(current.val);
            current = current.next;
        }

        for(int low = 0, high = list.size() - 1; low < high; low++, high--) {
            if(list.get(low) != list.get(high)) {
                return false;
            }
        }

        return true;
    }
}
