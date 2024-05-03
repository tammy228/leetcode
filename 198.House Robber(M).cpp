#include <iostream>
#include <vector>
using namespace std;
/*
 * My Solution
 * *(DP)
 * Ex: [1,2,3,1]
 * idea: 整體概念，以第0個來說，max(nums[0]+nums[2-n], nums[1-n])
 * 1. use array to store the maximum
 *
 * Time: O(N)
 * Space: O(N)
 *
 * Edge case:
 * 1. One element
 */
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[nums.size() - 1];
}

/**
 * Optimize
 *
 * since we only care n-2 and n-1, we use two variable to store
 *
 * Time: O(N) -> N is nums.size()
 * Space: O(1) -> for two variables
 *
 * Edge Case:
 * 1. if nums.size() == 1, we won't able to compare
 *
 */
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    int prev = 0, prev_2 = 0;
    prev_2 = nums[0];
    prev = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        int temp = max(prev_2 + nums[i], prev);
        prev_2 = prev;
        prev = temp;
    }
    return max(prev_2, prev);
}
