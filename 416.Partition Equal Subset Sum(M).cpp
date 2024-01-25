#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * My Solution
 *
 * At first, i was thinking about using backtracking to found all combination of subset sum, and then find if it contains
 * total_sum/2, but it will cause time limit
 *
 * The key is to find all subset sum, therefore we can use set to reduce the redundant finding
 *
 * **If you dry run the code, you will understand why we need a temp set
 *
 * Time: O(N * sum(nums))
 * Space: O(sum(nums))
 */
bool canPartition1(vector<int>& nums) {
    int total_sum = 0;
    for(int num : nums)
        total_sum += num;

    if(total_sum % 2  != 0) return false;

    unordered_set<int> sums;
    sums.insert(0);
    for(int i=0; i<nums.size(); i++)
    {
        unordered_set<int> temp_sums;
        temp_sums = sums;
        for(auto &sum : sums)
        {
            if(sum + nums[i] == (total_sum / 2))
                return true;
            else
                temp_sums.insert(sum+nums[i]);
        }
        sums = temp_sums;
    }
    return false;
}

/*
 * Optimize
 *
 * using dp array instead of set

 */
bool canPartition2(vector<int>& nums) {
    int total_sum = 0;
    for(int num : nums)
        total_sum += num;

    if(total_sum % 2  != 0) return false;
    vector<vector<bool>> dp (nums.size() + 1, vector<bool>(total_sum/2+1, false));
    // init dp
    for (int i=0; i<total_sum/2 + 1; i++)
    {
        dp[0][i] = false;
    }
    for (int i=0; i<nums.size() + 1; i++)
    {
        dp[i][0] = true;
    }
    for (int i=1; i<nums.size() + 1; i++)
    {
        for (int j=1; j<total_sum/2 + 1; j++)
        {
            if (j >= nums[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];  // consider take num and not take num
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[nums.size()][total_sum/2];
}
/*
 * Optimize2
 *
 * Turn 2d dp array to 1d, make sure the transform need to be updated from right to left
 * Because, 1d is to simulate previous information, if we update from left to right, we will not get previous information
 * Time: O(N * sum(nums)/2)
 * Space: O(sum(nums)/2)
 */
bool canPartition3(vector<int>& nums) {
    int total_sum = 0;
    for(int num : nums)
        total_sum += num;

    if(total_sum % 2  != 0) return false;
    vector<bool> dp (total_sum/2+1, false);
    // init dp
    dp[0] = true;
    for (auto& num : nums)
    {
        for(int i = total_sum/2; i > 0; i--)
        {
            if(i >= num)
                dp[i] = dp[i] || dp[i-num];
        }
    }
    return dp[total_sum/2];
}