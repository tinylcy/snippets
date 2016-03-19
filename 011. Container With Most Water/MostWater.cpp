/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 */

 /* 
  * 贪心的思想，从两边开始往中间靠拢，对于first和last，如果height[first]<height[last]，那么
  * last往中间靠只会减小面积，所以每次选择两边较小的一个往中间缩以希望增大面积。
  */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int min(int x,int y){
        return x<=y?x:y;
    }

    int maxArea(vector<int>& height) {
        int first=0;
        int last=height.size()-1;
        int maxArea=0;
        while(first<last){
            int area=(min(height[first],height[last])*(last-first));
            if(area>maxArea){
                maxArea=area;
            }
            if(height[first]<height[last]){
                first++;
            }else{
                last--;
            }
        }
        return maxArea;
    }
};

int main()
{
    vector<int> height;
    height.push_back(3);
    height.push_back(7);
    height.push_back(2);
    height.push_back(5);
    height.push_back(4);
    Solution object;
    cout<<object.maxArea(height)<<endl;
    return 0;
}
