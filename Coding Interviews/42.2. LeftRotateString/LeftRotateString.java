package algorithm;

/**
 * Created by chenyangli on 17/2/4.
 */
public class LeftRotateString {

    public static String leftRotate(String str, int k) {
        if (str == null || str.length() == 0 || k < 0) {
            return null;
        }
        int rotateNum = k % str.length();
        String twoStr = str + str;

        return twoStr.substring(rotateNum, str.length() + rotateNum);
    }

    public static void main(String[] args) {
        String str = "abcdefg";
        String rotated = leftRotate(str, 2);
        System.out.println("rotated = " + rotated);
    }

}
