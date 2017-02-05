package algorithm;

/**
 * Created by chenyangli on 17/2/5.
 */
public class LastNumberInCircle {

    private static class Node {
        int value;
        Node next;

        Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }
    }

    public static int lastNumberInCircle(int n, int m) {
        if (n < 2) {
            throw new IllegalArgumentException("n must > 2");
        }

        Node head = constructCircle(n);

        Node current, preCurrent;
        current = head.next;
        preCurrent = head;
        int count = m - 1;
        while (current != preCurrent) {
            while (--count > 0) {
                current = current.next;
                preCurrent = preCurrent.next;
            }
            System.out.println(current.value + " deleted.");
            preCurrent.next = current.next;
            current = preCurrent.next;
            count = m;
        }

        return current.value;
    }

    private static Node constructCircle(int n) {
        Node head = new Node(n - 1, null);
        Node tail = head;
        for (int i = n - 2; i >= 0; i--) {
            Node node = new Node(i, head);
            head = node;
        }
        tail.next = head;
        return head;
    }

    public static void main(String[] args) {
        System.out.println("last number in circle is: " + lastNumberInCircle(4000, 997));
    }
}
