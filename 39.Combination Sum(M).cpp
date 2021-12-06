#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*
 * My Solution
 * *(dfs, backtracking)
 * 0. sort first with fast execution
 * 1. similar to dfs, use an array to keep track of current candidates
 * 2. during dfs:
 *    add current candidate
 *    don't add current candidate (avoid duplicate combinations Ex:[2,2,3] [2,3,2])
 * 3. stop:
 *    candidates sum >= target
 *    no candidate to add
 */

void dfs(vector<vector<int>>& ans, vector<int>& current, int index, const vector<int>& candidates, const int target){
    if(index == candidates.size() || accumulate(current.begin(), current.end(), 0) > target)
        return;
    if(target == accumulate(current.begin(), current.end(), 0)){
        ans.push_back(current);
        return;
    }
    current.push_back(candidates[index]);
    dfs(ans,current, index, candidates, target);

    current.pop_back();
    dfs(ans, current, ++index, candidates, target);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;
    dfs(ans, current, 0, candidates, target);
    return ans;
}
