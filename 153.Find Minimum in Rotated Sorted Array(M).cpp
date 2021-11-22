#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * * (Binary Search)
 * 1. Compare left pointer and middle
 *    left < mid: left = mid
 *    left > mid: right = mid
 *    stop: left == mid || In the ascending subarray
 * Edge Case
 *  (1) One element
 */
int findMin(vector<int>& nums) {
    int left=0, right=nums.size()-1;
    if(nums.size() == 1)
        return nums[0];
    while(left < right){
        int mid = (left + right) / 2;
        if(nums[right] > nums[left])
            return nums[left];
        if(nums[mid] > nums[left])
            left = mid;
        else if(nums[mid] < nums[left])
            right = mid;
        else
            if(nums[left] > nums[right])
                return nums[right];
            else
                return nums[left];
    }
    return 0;
}

