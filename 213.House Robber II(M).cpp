#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * 1. reuse house robber, but with two direction, both without last element, because we can not
 *    pick firs and last element at the same time.
 *
 * Time: O(n)
 *
 * Edge Case:
 * 1. one element
 * 2. two element
 */
int rob2(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);
    vector<int> dp(nums.size()-1, 0);
    // 1.
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i=2; i<nums.size()-1; i++)
       dp[i] = max(nums[i]+ dp[i-2], dp[i-1]);

    int ans = dp[nums.size()-2];
    dp.clear();
    // 2.
    reverse(nums.begin(), nums.end());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i=2; i<nums.size()-1; i++)
        dp[i] = max(nums[i]+ dp[i-2], dp[i-1]);

    return max(ans, dp[nums.size()-2]);
}