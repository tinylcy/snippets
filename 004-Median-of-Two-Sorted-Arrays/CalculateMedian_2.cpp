/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 */

/* 每次从nums1和nums2首部取一个较小的数字，时间复杂度为O(n)，在leetcode上可以AC */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        int a=0,b=0;
        if(len1==0&&len2==0){
            return 0;
        }
        if(len1>0&&len2==0){
            a=nums1[len1/2-1];
            b=nums1[len1/2];
            if(len1%2==0){
                return (double)(a+b)/2;
            }else{
                return (double)b;
            }
        }
        if(len1==0&&len2>0){
            a=nums2[len2/2-1];
            b=nums2[len2/2];
            if(len2%2==0){
                return (double)(a+b)/2;
            }else{
                return (double)b;
            }
        }
        int length=len1+len2;
        int index1=0,index2=0,count=-1,number=0;
        bool isOver=false;
        while(index1<len1&&index2<len2){
            if(nums1[index1]<=nums2[index2]){
                number=nums1[index1++];
            }else{
                number=nums2[index2++];
            }
            count++;
            if(count==length/2-1){
                a=number;
            }
            if(count==length/2){
                b=number;
                isOver=true;
                break;
            }
        }
        if(!isOver){
            while(index1<len1){
                number=nums1[index1++];
                count++;
                if(count==length/2-1){
                    a=number;
                }
                if(count==length/2){
                    b=number;
                    break;
                }
            }
            while(index2<len2){
                number=nums2[index2++];
                count++;
                if(count==length/2-1){
                    a=number;
                }
                if(count==length/2){
                    b=number;
                    break;
                }
            }
        }
        if(length%2==0){
            return (double)(a+b)/2;
        }else{
            return (double)b;
        }
    }
};

int main()
{
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(2);
    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(5);
    nums2.push_back(6);
    Solution object;
    cout<<object.findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}
