package algorithm;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by chenyang li.
 */
public class SortArrayForMinNumber {

    public static String minNumber(int[] num, int len) {
        ArrayList<Entry> list = new ArrayList<Entry>();
        for (int i = 0; i < len; i++) {
            Entry entry = new Entry(num[i]);
            list.add(entry);
        }
        Object[] entries = list.toArray();
        Arrays.sort(entries);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; i++) {
            sb.append(((Entry) entries[i]).value);
        }
        return sb.toString();
    }

    public static class Entry implements Comparable<Entry> {
        public int value;

        public Entry(int value) {
            this.value = value;
        }

        public int compareTo(Entry o) {
            String mn = String.valueOf(value) + String.valueOf(o.value);
            String nm = String.valueOf(o.value) + String.valueOf(value);
            if (mn.compareTo(nm) < 0) {
                return -1;
            } else if (mn.compareTo(nm) > 0) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    public static void main(String[] args) {
        int[] num = {3, 32, 23, 44, 12, 321};
        System.out.println(minNumber(num, 6));
    }
}
