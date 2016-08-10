package _162FindPeakElement;

/**
 * 
 * @author tinylcy
 * 
 *         A peak element is an element that is greater than its neighbors.
 *         Given an input array where num[i] ≠ num[i+1], find a peak element and
 *         return its index. The array may contain multiple peaks, in that case
 *         return the index to any one of the peaks is fine.
 * 
 *         You may imagine that num[-1] = num[n] = -∞.
 * 
 *         For example, in array [1, 2, 3, 1], 3 is a peak element and your
 *         function should return the index number 2.
 *
 */
public class FindPeakElement {

	public int findPeakElement(int[] nums) {
		int N = nums.length;
		if (N == 1) {
			return 0;
		}
		if (nums[0] > nums[1]) {
			return 0;
		}
		if (nums[N - 1] > nums[N - 2]) {
			return N - 1;
		}
		int low = 0, high = N - 1;
		while (low < high) {
			int mid = (low + high) / 2;
			if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
				return mid;
			} else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
				low = mid;
			} else if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) {
				low = mid;
			} else {
				high = mid;
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		FindPeakElement peak = new FindPeakElement();
		int[] nums = { -4, -3, -2, -1, 4, 3, 1, 2 };
		System.out.println(peak.findPeakElement(nums));
	}
}
