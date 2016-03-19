package _215_kth_largest_element_in_an_array;

/**
 * 
 * @author tinylcy
 * 
 *         Find the kth largest element in an unsorted array. Note that it is
 *         the kth largest element in the sorted order, not the kth distinct
 *         element.
 * 
 *         For example, Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 *         Note: You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * 
 *
 */

public class KthLargestElement {

	public int findKthLargest(int[] nums, int k) {
		int N = nums.length;
		int[] aux = new int[N + 1];
		for (int i = 0; i < N; i++) {
			aux[i + 1] = nums[i];
		}
		for (int j = N / 2; j >= 1; j--) {
			sink(aux, j, N);
		}
		int count = 1;
		int num = 0;
		while (count <= k) {
			if (count == k) {
				num = aux[1];
				break;
			}
			exch(aux, 1, N);
			N--;
			sink(aux, 1, N);
			count++;
		}
		return num;
	}

	private void exch(int[] aux, int i, int j) {
		int t = aux[i];
		aux[i] = aux[j];
		aux[j] = t;
	}

	private void sink(int[] aux, int k, int N) {
		while (2 * k <= N) {
			int j = 2 * k;
			if (j < N && aux[j] < aux[j + 1]) {
				j = j + 1;
			}
			if (aux[k] > aux[j]) {
				break;
			}
			exch(aux, k, j);
			k = j;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 3, 2, 1, 5, 6, 4 };
		KthLargestElement kth = new KthLargestElement();
		System.out.println(kth.findKthLargest(nums, 2));
	}
}
