package _153_FindMinimumInRotatedSortedArray;

/**
 * 
 * @author tinylcy
 * 
 *         Suppose a sorted array is rotated at some pivot unknown to you
 *         beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). Find
 *         the minimum element. You may assume no duplicate exists in the array.
 *
 */
public class FindMinimum {

	public int findMin(int[] nums) {
		int low = 0;
		int high = nums.length - 1;
		return findMin(nums, low, high);
	}

	public int findMin(int[] nums, int low, int high) {
		while (low < high - 1) {
			int mid = (low + high) / 2;
			if (nums[mid] >= nums[low] && nums[mid] >= nums[high]) {
				low = mid;
			} else if (nums[mid] <= nums[low] && nums[mid] <= nums[high]) {
				high = mid;
			} else if (nums[mid] >= nums[low] && nums[mid] <= nums[high]) {
				high = low;
			}
		}
		return nums[low] <= nums[high] ? nums[low] : nums[high];
	}

	public static void main(String[] args) {

		FindMinimum minimum = new FindMinimum();
		int[] nums = { 1, 2, 3 };
		System.out.println(minimum.findMin(nums));
	}
}
