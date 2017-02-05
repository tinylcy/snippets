package algorithm;

/**
 * Created by chenyangli on 17/2/4.
 */
public class ReverseWordsInSentence {

    public static String reverse(String sentence) {
        String reversed = reverseSentence(sentence);
        char[] chars = reversed.toCharArray();
        int start, end;
        int i = 0;
        while (i < chars.length) {
            while (chars[i] == ' ') {
                i++;
            }
            start = i;
            while (i < chars.length && chars[i] != ' ') {
                i++;
            }
            end = i;
            reverseWord(chars, start, end);
        }

        return new String(chars);
    }

    private static String reverseSentence(String sentence) {
        if (sentence == null || sentence.length() == 0) {
            return null;
        }
        char[] chars = sentence.toCharArray();
        for (int i = 0, j = chars.length - 1; i <= j; i++, j--) {
            char tmp = chars[i];
            chars[i] = chars[j];
            chars[j] = tmp;
        }
        return new String(chars);
    }

    private static void reverseWord(char[] sentence, int start, int end) {
        for (int i = start, j = end - 1; i <= j; i++, j--) {
            char tmp = sentence[i];
            sentence[i] = sentence[j];
            sentence[j] = tmp;
        }
    }


    public static void main(String[] args) {
        String sentence = "I am   a student.  ";
        String reversed = reverse(sentence);
        System.out.println("reversed sentence = " + reversed);
    }

}
