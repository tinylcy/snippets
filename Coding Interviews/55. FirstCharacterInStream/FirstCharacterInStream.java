package algorithm;

/**
 * Created by chenyang li.
 */
public class FirstCharacterInStream {

    public static char firstCharacterInStream(char [] chars) {
        int [] hash = new int[256];

        for(int i = 0; i < hash.length; i++) {
            hash[i] = 0;
        }

        for(int i = 0; i < chars.length; i++) {
            int index = chars[i] - 'a';
            hash[index]++;
        }

        for(int i = 0; i < chars.length; i++) {
            if(hash[chars[i] - 'a'] == 1) {
                return chars[i];
            }
        }

        return 0;
    }

    public static void main(String [] args) {
        char [] chars = "google".toCharArray();
        System.out.println(firstCharacterInStream(chars));
    }
}
