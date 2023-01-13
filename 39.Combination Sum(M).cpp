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

/*
 * Optimize
 *
 * since we can not choose duplicate combinations, we use specific tree method to achieve.
 * Tree will have two children, one is to choose candidate[i], the other path will not.
 * During choosing, we will check if we match target, or exceed target(To check this we can use minus instead of accu.)
 *
 * Time:
 * O(2^target): in the decision tree, we have two paths, and the height will be added most time of target.
 */

void op_dfs(vector<vector<int>>& ans, vector<int>& cur, int index, vector<int>& candidates, int target){
    if(index == candidates.size() || target < 0)
        return;
    if(target == 0){
        ans.push_back(cur);
        return;
    }
    // Don't choose candidates[index], and move on to next candidates.
    // it can only be done, when cur is not pass-by-address, but it's much slower.
    // op_dfs(ans, cur, index+1, candidates, target);

    // Choose candidates[index]
    cur.push_back(candidates[index]);
    op_dfs(ans, cur, index, candidates, target-candidates[index]);

    // Don't choose candidates[index], and move on to next candidates.
    cur.pop_back();
    op_dfs(ans, cur, index+1, candidates, target);
}