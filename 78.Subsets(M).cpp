#include <vector>
using namespace std;

/*
 * My Solution
 * Use backtracking to find all combinations
 */
void backtracking(vector<vector<int>>& ans, vector<int>& nums, vector<int>& comb, int& index, vector<int>& used)
{
    if (index == nums.size())
    {
        ans.push_back(comb);
        return;
    }
    for (int i=0; i<nums.size(); i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            comb.push_back(nums[index]);
            backtracking(ans, nums, comb, ++index, used);
            comb.pop_back();
            used[i] = 0;
        }
    }

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