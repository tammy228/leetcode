#include <vector>
using namespace std;
/*
 * My Solution
 * (Backtracking)
 * All permutation combination, if we have 3 integers, is 3*2*1 = 6
 * Use swap to achieve permutation
 *
 * Time:
 * O(n!)
 *
 * Space:
 * O(n!): calling stack
 */
void solve(vector<int>& nums, vector<vector<int>>& result, int begin){
    if(begin == nums.size())
        result.push_back(nums);
    for(int i=begin; i<nums.size(); i++){
        swap(nums[i], nums[begin]);
        solve(nums, result, begin+1);
        swap(nums[i], nums[begin]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    solve(nums, result, 0);
    return result;
}