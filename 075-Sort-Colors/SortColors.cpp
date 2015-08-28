/* Given an array with n objects colored red, white or blue, sort them so that objects of the
same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with
total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space? */

/*
 *思想：最直接的就是统计0,1,2的个数然后重写一遍数组，但是人家已经说了不让用。
 *设置2个游标left和right分别指向新开辟的数组sorted的最左和最右，遍历数组，
 *如果是0，sorted[left++]=0,如果是2，sorted[right--]=2,遍历完了，left和right之间都是1.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length=nums.size();
        if(length==0||length==1){
            return;
        }
        vector<int> sorted(length,0); //初始化
        int left=0,right=length-1;
        for(int index=0;index<length;index++){
            if(nums[index]==0){
                sorted[left++]=0;
            }else if(nums[index]==2){
                sorted[right--]=2;
            }
        }
        for(int index=left;index<=right;index++){
            sorted[index]=1;
        }
        nums=sorted;
    }
};

int main()
{
    Solution object;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    object.sortColors(nums);
    return 0;
}
