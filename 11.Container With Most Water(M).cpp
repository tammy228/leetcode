#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * *(Two Pointer)
 * 1. while left < right, calculate the area
 *    if height[left] <= height[right] : left ++
 *    else right --
 *
 * Time: O(n)
 *
 * Edge Case:
 * 1. Only two element: return smaller height
 */
int maxArea(vector<int>& height) {
    if(height.size() == 2) return height[0] > height[1] ? height[1] : height[0];
    int left=0, right=height.size()-1;
    int ans=0;
    while(left < right){
        int area = (right-left) * (min(height[right],height[left]));
        ans = max(area, ans);
        if(height[left] <= height[right]){
            while(height[left+1] <= height[left] && left < right) left++;
            left++;
        }else{
            while(height[right-1] <= height[right] && left < right) right--;
            right--;
        }
    }
    return ans;
}

