/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

 /*
  * 思想：从右往左找，找到第一对递增的2个数字，它们的下标分别用i,j标记(i<j)，如果没有找到的话
  * 就说明当前的序列已经是最大的了，否则，再从最右开始，找到第一个大于i所指向的数nums[k]，并将
  * nums[k]和nums[i]相互替换。最后，将j之后（包括j）的整个递减的序列逆置。
  */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(vector<int> &nums,int begin,int end){
        while(begin<end){
            int tmp=nums[begin];
            nums[begin]=nums[end];
            nums[end]=tmp;
            ++begin;
            --end;
        }
    }

    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
            return;
        int i=nums.size()-2;
        int j=nums.size()-1;
        while(i>=0&&nums[i]>=nums[j]){
            --i;
            --j;
        }
        if(i<0){
            reverse(nums,0,nums.size()-1);
        }else{
            int k=nums.size()-1;
            while(k>i){
                if(nums[k]>nums[i]){
                    int tmp=nums[k];
                    nums[k]=nums[i];
                    nums[i]=tmp;
                    reverse(nums,j,nums.size()-1);
                    break;
                }
                --k;
            }
        }
        return;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    Solution object;
    object.nextPermutation(nums);
    for(unsigned int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl; //print 7,3,3,1,2,2,5
    return 0;
}
