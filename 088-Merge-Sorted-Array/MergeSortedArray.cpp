/* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 * Note:
 *
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

 /* 思想：从最后开始merge */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index=m+n-1;
        int index_a=m-1;
        int index_b=n-1;
        if(m==0){
            for(int i=0;i<n;i++){
                nums1[i]=nums2[i];
            }
            return;
        }
        while(index>=0){
            if(index_a>=0&&index_b>=0){
                if(nums1[index_a]>=nums2[index_b]){
                    nums1[index]=nums1[index_a];
                    index_a--;
                }else{
                    nums1[index]=nums2[index_b];
                    index_b--;
                }
            }else if(index_b>=0&&index_a<0){
                nums1[index]=nums2[index_b];
                index_b--;
            }
            index--;
        }
        return;
    }
};

int main()
{
    vector<int> nums1;
    vector<int> nums2;
    nums1.resize(10);
    nums1[0]=2;
    nums1[1]=0;
    nums2.push_back(1);
    nums2.push_back(4);
    nums2.push_back(6);
    nums2.push_back(8);
    Solution object;
    object.merge(nums1,1,nums2,1);
    for(unsigned int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    return 0;
}
