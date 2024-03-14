#include <vector>
using namespace std;

/*
 * My Solution
 * Use backtracking to find all combinations
 * After dry run, find out this question doesn't require for loop
 */
void backtracking(vector<vector<int>>& ans, vector<int>& nums, vector<int>& comb,  int index)
{
    if (index == nums.size())
    {
        ans.push_back(comb);
        return;
    }

    comb.push_back(nums[index]);
    backtracking(ans, nums, comb, index + 1);
    comb.pop_back();
    backtracking(ans, nums, comb, index + 1);

}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    ans.push_back({});
    vector<int> comb;
    vector<int> used(nums.size(), 0);
    int index = 0;
    backtracking(ans, nums, comb, index, used);
    return ans;
}