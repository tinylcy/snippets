/* Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
It doesn't matter what you leave beyond the new length. */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0,key=0,count=0;
        for(unsigned int i=0;i<nums.size();i++){
            if(i==0){
                key=nums[i];
                count=1;
                index++;
            }else{
                if(nums[i]==key&&count<2){
                    nums[index]=nums[i];
                    index++;
                    count++;
                }else if(nums[i]!=key){
                    key=nums[i];
                    nums[index]=nums[i];
                    index++;
                    count=1;
                }
            }
        }
        return index;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    Solution object;
    cout<<object.removeDuplicates(nums)<<endl;
    cout<<endl;
    return 0;
}
