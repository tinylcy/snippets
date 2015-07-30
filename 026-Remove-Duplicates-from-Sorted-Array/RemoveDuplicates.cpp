/* Given a sorted array, remove the duplicates in place such that each element appear
 * only once and return the new length.

 * Do not allocate extra space for another array, you must do this in place with constant memory.

 * For example,Given input array nums = [1,1,2],

 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length=0,key=0;
        unsigned int index=0,numsLen=0;
        numsLen=nums.size();
        while(index<numsLen){
            if(index==0){
                key=nums[index];
                nums[length++]=nums[index++];
            }else{
                if(nums[index]==key){
                    while(index<numsLen&&nums[index]==key){
                        ++index;
                    }
                }
                if(index<numsLen){  //consider the situation of 1,2,2
                    key=nums[index];
                    nums[length++]=nums[index++];
                }
            }
        }
        return length;
    }
};

int main()
{
    Solution object;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    int length=object.removeDuplicates(nums);
    cout<<"length="<<length<<endl;
    return 0;
}
