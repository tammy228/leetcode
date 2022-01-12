#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * *(DP)
 * 1. Think of brute force first, then improve the complexity
 * 2. bottom-up method, check if that index can reach to last index.
 *
 * Time: O(n^2)
 */
//bool canJump(vector<int>& nums) {
//    vector<bool> dp(nums.size(), false);
//    dp[nums.size()-1] = true;
//    for(int i=nums.size()-2; i>=0; i--){
//        for(int step=1; step<=nums[i]; step++){
//            if(dp[i+step] == true) {
//                dp[i] = true;
//                break;
//            }
//        }
//    }
//    return dp[0];
//}
/*
 * Optimize
 * *(Greedy)
 * 1. shift the goal position forward, if the current index can reach(over) to the goal position.
 *
 * Time: O(n)
 * Space: no
 */
bool canJump(vector<int> & nums){
    int goal_position = nums.size()-1;
    for(int i=nums.size()-2; i>=0; i--){
        if(nums[i] + i >= goal_position)
            goal_position = i;
    }
    if(goal_position == 0)
        return true;
    else
        return false;
}