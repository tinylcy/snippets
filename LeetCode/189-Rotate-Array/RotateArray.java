package _189RotateArray;

/**
 * 
 * @author tinylcy
 * 
 *         Rotate an array of n elements to the right by k steps.
 * 
 *         For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is
 *         rotated to [5,6,7,1,2,3,4].
 *
 */

public class RotateArray {

	public void rotate(int[] nums, int k) {
		int N = nums.length;
		k = k % N;
		int[] aux = new int[N];
		for (int i = 0; i < N; i++) {
			aux[i] = nums[i];
		}
		for (int i = N - k, j = 0; j < N; i++, j++) {
			nums[j] = aux[i % N];
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 2 };
		RotateArray rotate = new RotateArray();
		rotate.rotate(nums, 3);
		for (int i = 0; i < nums.length; i++) {
			System.out.print(nums[i] + " ");
		}
	}
}
