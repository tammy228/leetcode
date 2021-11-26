#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * *(DP)
 * Think of Brute Force first(樹狀圖)
 * Ex: [1,2,4,3]
 *                               root
 * indices:                 (0)|                 (1)|             (2)|      (3)|
 * ans:                     [1]                   [2]             [4]      [3]
 * indices       (1)|       (2)|     (3)|     (2)|    (3)|        (X)       (X)
 * ans:          [1,2]      [1,4]    [1,3]    [2,4]   [2,3]
 * indices:  (2)|    (3)|     (X)      (X)     (X)      (X)
 * ans:     [1,2,4] [1,2,3]
 *            (X)      (X)
 * 1. iterate the array reversely
 *    n: dp[n] = 1 -> start with last element must be length 1
 *    n-1: dp[n-1] = dp[n]>dp[n-1] ? 2 : 1 -> if last element bigger than last-2 element then the length is 2
 *
 * Time: O(n^2)
 */
int lengthOfLIS(vector<int>& nums) {
    if(nums.size() == 1) return 1;
    if(nums.size() == 2) return nums[nums.size()-1] > nums[nums.size()-2] ? 2 : 1;
    vector<int> dp(nums.size(), 1);
    dp[nums.size()-1] = 1;
    dp[nums.size()-2] = nums[nums.size()-1] > nums[nums.size()-2] ? 2 : 1;
    for(int i=nums.size()-3; i>=0; i--){
        for(int j=nums.size()-1; j>i; j--){
            if(nums[j] > nums[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}
