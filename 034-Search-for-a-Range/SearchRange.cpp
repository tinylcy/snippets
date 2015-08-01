/*
 * Given a sorted array of integers, find the starting and ending position of a given target value.

 * Your algorithm's runtime complexity must be in the order of O(log n).

 * If the target is not found in the array, return [-1, -1].

 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

/*
 * 思路：多次运用二分查找，先找到一个target的下标pivot（如果存在的话），然后在pivot左侧再次二分查找target，
 * 如果找到的话就更新left，并再在新的left左侧再次二分查找，直到pivot返回-1，此时left即可确定；同理，寻找right，
 * 在第一次找到的pivot右侧二分查找target，如果找到就更新right，并在新的right右侧继续二分查找target，找到便、
 * 更新right，直到pivot返回-1，此时left和right都可确定。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int BinarySearch(vector<int> &nums,int low,int high,int target){
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                low=mid+1;
            }
            if(target<nums[mid]){
                high=mid-1;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        int left=0,right=0;
        int pivot=BinarySearch(nums,0,nums.size()-1,target);
        if(pivot==-1){
            left=right=-1;
        }else{
            int flag=pivot;
            int low=0,high=pivot-1;
            left=right=pivot;
            while(pivot!=-1&&low<=high){ //找left
                pivot=BinarySearch(nums,low,high,target);
                if(pivot!=-1){
                    left=pivot;
                    high=pivot-1;
                }else{
                    break;
                }
            }
            low=flag+1;
            high=nums.size()-1;
            pivot=BinarySearch(nums,low,high,target);
            while(pivot!=-1&&low<=high){ //找right
                pivot=BinarySearch(nums,low,high,target);
                if(pivot!=-1){
                    right=pivot;
                    low=pivot+1;
                }else{
                    break;
                }
            }
        }
        answer.push_back(left);
        answer.push_back(right);
        return answer;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(9);
    nums.push_back(10);
    nums.push_back(10);
    Solution object;
    vector<int> answer=object.searchRange(nums,7);
    cout<<"left="<<answer[0]<<" right="<<answer[1]<<endl;
    return 0;
}
