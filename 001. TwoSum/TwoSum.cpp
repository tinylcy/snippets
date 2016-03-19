/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,  
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int value;
    int position;
};

class Solution
{
public:
    void QuickSort(Node a[],int low,int high)
    {
        if(low>=high)
        {
            return;
        }
        int first=low;
        int last=high;
        Node key=a[first];
        while(first<last)
        {
            while(first<last&&a[last].value>=key.value)
            {
                --last;
            }
            a[first].position=a[last].position;
            a[first].value=a[last].value;
            while(first<last&&a[first].value<=key.value)
            {
                ++first;
            }
            a[last].position=a[first].position;
            a[last].value=a[first].value;
        }
        a[first].position=key.position;
        a[first].value=key.value;
        QuickSort(a,low,first-1);
        QuickSort(a,first+1,high);
    }

    vector<int> twoSum(vector<int>& nums, int target)
    {
        Node numsArray[nums.size()];
        for(unsigned int i=0; i<nums.size(); i++)
        {
            numsArray[i].position=i;
            numsArray[i].value=nums[i];
        }
        QuickSort(numsArray,0,nums.size()-1);
        int low=0;
        int high=nums.size()-1;
        vector<int> result;
        while(low<high)
        {
            if(numsArray[low].value+numsArray[high].value==target)
            {
                break;
            }
            if(low<high&&numsArray[low].value+numsArray[high].value<target)
            {
                ++low;
            }
            else if(low<high&&numsArray[low].value+numsArray[high].value>target)
            {
                --high;
            }
        }
        int index1=numsArray[low].position;
        int index2=numsArray[high].position;
        if(numsArray[low].position>numsArray[high].position)
        {
            index1=numsArray[high].position;
            index2=numsArray[low].position;
        }
        result.push_back(index1+1);
        result.push_back(index2+1);
        return result;
    }
};

int main()
{
    Solution object;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    vector<int> result=object.twoSum(nums,18);
    cout<<"index1="<<result[0]<<" index2="<<result[1]<<endl;
}

