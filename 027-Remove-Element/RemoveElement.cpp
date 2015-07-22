/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int length=nums.size();
        int start=0;
        for(int index=0; index<length; ++index)
        {
            if(nums[index]!=val)
            {
                nums[start++]=nums[index];
            }
        }
        return start;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    Solution object;
    cout<<object.removeElement(nums,4)<<endl;
    return 0;
}
