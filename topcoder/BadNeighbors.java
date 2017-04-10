package topcoder;

/**
 * Created by chenyang li.
 * <p/>
 * Problem Statement
 * <p/>
 * The old song declares "Go ahead and hate your neighbor", and the residents of Onetinville have taken those words to heart.
 * Every resident hates his next-door neighbors on both sides. Nobody is willing to live farther away from the town's well than his neighbors,
 * so the town has been arranged in a big circle around the well. Unfortunately, the town's well is in disrepair and needs to be restored.
 * You have been hired to collect donations for the Save Our Well fund.
 * <p/>
 * Each of the town's residents is willing to donate a certain amount, as specified in the int[] donations, which is listed in clockwise order around the well.
 * However, nobody is willing to contribute to a fund to which his neighbor has also contributed. Next-door neighbors are always listed consecutively in donations,
 * except that the first and last entries in donations are also for next-door neighbors. You must calculate and return the maximum amount of donations that can be collected.
 * <p/>
 * <p/>
 * Definition
 * <p/>
 * Class:	BadNeighbors
 * Method:	maxDonations
 * Parameters:	int[]
 * Returns:	int
 * Method signature:	int maxDonations(int[] donations)
 * (be sure your method is public)
 * <p/>
 * <p/>
 * Constraints
 * -	donations contains between 2 and 40 elements, inclusive.
 * -	Each element in donations is between 1 and 1000, inclusive.
 * <p/>
 * Examples
 * 0)
 * <p/>
 * { 10, 3, 2, 5, 7, 8 }
 * Returns: 19
 * The maximum donation is 19, achieved by 10+2+7. It would be better to take 10+5+8 except that the 10 and 8 donations are from neighbors.
 * 1)
 * <p/>
 * { 11, 15 }
 * Returns: 15
 * 2)
 * <p/>
 * { 7, 7, 7, 7, 7, 7, 7 }
 * Returns: 21
 * 3)
 * <p/>
 * { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 }
 * Returns: 16
 * 4)
 * <p/>
 * { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
 * 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
 * 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 }
 * Returns: 2926
 */
public class BadNeighbors {

    public static int maxDonations(int[] donations) {
        int[] donationsA = new int[donations.length - 1];
        int[] donationsB = new int[donations.length - 1];
        for (int i = 0; i < donations.length - 1; i++) {
            donationsA[i] = donations[i];
        }
        for (int i = 1; i < donations.length; i++) {
            donationsB[i - 1] = donations[i];
        }

        int maxDonationsA = maxDonations(donationsA, donationsA.length);
        int maxDonationsB = maxDonations(donationsB, donationsB.length);
        return maxDonationsA > maxDonationsB ? maxDonationsA : maxDonationsB;
    }

    private static int maxDonations(int[] donations, int len) {
        int[] dp = new int[len];
        for (int i = 0; i < len; i++) {
            if (i == 0 || i == 1) {
                dp[i] = donations[i];
            } else {
                int max = dp[i - 2];
                for (int j = i - 2; j >= 0; j--) {
                    if (dp[j] > max) {
                        max = dp[j];
                    }
                }
                dp[i] = max + donations[i];
            }
        }

        int maxDonations = Integer.MIN_VALUE;
        for (int i = 0; i < len; i++) {
            if (dp[i] > maxDonations) {
                maxDonations = dp[i];
            }
        }
        return maxDonations;
    }

    public static void main(String[] args) {
        int[] donationsA = {10, 3, 2, 5, 7, 8};
        System.out.println(maxDonations(donationsA));
        int[] donationsB = {11, 15};
        System.out.println(maxDonations(donationsB));
        int[] donationsC = {7, 7, 7, 7, 7, 7, 7};
        System.out.println(maxDonations(donationsC));
        int[] donationsD = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
        System.out.println(maxDonations(donationsD));
        int[] donationsE = {94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
                6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
                52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72};
        System.out.println(maxDonations(donationsE));
    }
}
