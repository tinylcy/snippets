/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

/*在leetcode上可以AC，但是时间复杂度为O(nlog(n))*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        int length=nums1.size();
        if(length%2==0){
            return (double)(nums1[length/2]+nums1[length/2-1])/2;
        }else{
            return (double)nums1[length/2];
        }
    }
};

int main()
{
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(3);
    nums1.push_back(6);
    nums2.push_back(2);
    nums2.push_back(4);
    nums2.push_back(5);
    Solution object;
    cout<<object.findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}
