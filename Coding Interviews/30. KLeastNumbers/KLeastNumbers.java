package algorithm;

import java.util.*;

/**
 * Created by chenyang li.
 */
public class KLeastNumbers {

    public static Queue<Integer> getListKNumbers(List<Integer> list, int k) {
        Queue<Integer> queue = new PriorityQueue<Integer>(new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                int cmp = o1.compareTo(o2);
                if (cmp < 0) {
                    return 1;
                } else if (cmp > 0) {
                    return -1;
                } else {
                    return 0;
                }
            }
        });

        for (int i = 0; i < list.size(); i++) {
            int elem = list.get(i);
            if (queue.size() < k) {
                queue.add(elem);
            } else {
                int max = queue.peek();
                if (elem < max) {
                    queue.poll();
                    queue.add(elem);
                }
            }
        }
        return queue;
    }

    public static void main(String[] args) {
        List list = new ArrayList(Arrays.asList(4, 5, 1, 6, 2, 7, 3, 8));
        Queue<Integer> queue = getListKNumbers(list, 4);
        System.out.println(queue);
    }
}
