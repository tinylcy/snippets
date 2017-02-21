package algorithm;

/**
 * Created by chenyang li.
 */
public class StringToInt {

    public static boolean valid;

    public static int atoi(String str) {
        valid = true;
        if (str == null) {
            valid = false;
            return 0;
        }
        char[] array = str.toCharArray();
        int flag = 1;
        int i = 0;
        if (array[i] == '+') {
            i++;
        } else if (array[i] == '-') {
            flag = -1;
            i++;
        }

        long result = 0;
        if (i == 1 && array.length == 1) {
            valid = false;
            return 0;
        }
        while (i < array.length) {
            if (array[i] >= '0' && array[i] <= '9') {
                result = result * 10 + flag * (array[i] - '0');
            } else {
                result = 0;
                valid = false;
                break;
            }
            if ((flag == 1 && result > Integer.MAX_VALUE) || (flag == -1 && result < Integer.MIN_VALUE)) {
                result = 0;
                valid = false;
                break;
            }
            i++;
        }
        return (int) result;
    }

    public static void main(String[] args) {
        System.out.println(atoi("2147483647") + ", valid = " + valid);
        System.out.println(atoi("2147483648") + ", valid = " + valid);
        System.out.println(atoi(String.valueOf(Integer.MIN_VALUE)) + ", valid = " + valid);
        System.out.println(atoi("-") + ", valid = " + valid);
    }
}
