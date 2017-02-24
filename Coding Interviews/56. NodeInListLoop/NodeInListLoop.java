package algorithm;

/**
 * Created by chenyang li.
 */
public class NodeInListLoop {

    public static class Node {
        int value;
        Node next;

        public Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }
    }

    public static Node findEntryNode(Node head) {
        if (head == null) {
            return null;
        }
        if (!loopExist(head)) {
            return null;
        }
        int loopLength = getLoopLength(head);
        Node first = head, second = head;
        int count = loopLength;
        while (count-- > 0) {
            first = first.next;
        }
        while (first != second) {
            first = first.next;
            second = second.next;
        }
        return first;
    }

    private static int getLoopLength(Node head) {
        Node slow = head, fast = head.next.next;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next.next;
        }
        int length = 1;
        slow = slow.next;
        while (slow != fast) {
            slow = slow.next;
            length++;
        }
        return length;
    }

    public static boolean loopExist(Node head) {
        Node slow = head, fast = head.next;
        if (fast == null) {
            return false;
        }
        fast = fast.next;
        if (fast == null) {
            return false;
        }
        while (slow != fast) {
            if (fast == null) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Node node6 = new Node(6, null);
        Node node5 = new Node(5, node6);
        Node node4 = new Node(4, node5);
        Node node3 = new Node(3, node4);
        Node node2 = new Node(2, node3);
        Node node1 = new Node(1, node2);
        node6.next = node3;

        Node node7 = new Node(7, null);
        Node node8 = new Node(8, node7);
        node7.next = node8;

        System.out.println(findEntryNode(node1).value);
        System.out.println(findEntryNode(node7).value);
    }
}
