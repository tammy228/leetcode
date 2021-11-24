#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * 1. iterate the array and keep add the element
 * 2. if prefixSum <= 0: prefixSum = 0
 *    else prefixSum += element
 *
 * Time: O(n)
 */
int maxSubArray(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int ans=nums[0];
    int prefixSum=0;
    for(int i=1; i<nums.size(); i++){
        if(prefixSum <= 0)
            prefixSum = 0;
        prefixSum += nums[i];
        ans = max(ans, prefixSum);
    }
    return ans;
}