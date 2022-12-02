#include <vector>
using namespace std;

/*
 * My Solution
 * iterate all interval in origin intervals, compare with each interval with new_interval
 * it will only be three kinds of scenario.
 * 1. new_interval comes before ori_interval[i]
 *    push new_interval into result
 *    ori_interval[i] become new_interval
 * 2. new_interval comes after ori_interval[i]
 *    push ori_interval[i] into result
 * 3. overlapping
 *    new_interval = merge two intervals
 *
 * Time:
 * O(N)
 *
 * Space:
 * O(1): output vector doesn't count as extra space.
 */
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    for(int i=0; i<intervals.size(); i++){
        if(newInterval[1] < intervals[i][0]){
            result.push_back(newInterval);
            newInterval = intervals[i];
        }else if(newInterval[0] > intervals[i][1]){
            result.push_back(intervals[i]);
        }else{
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }
    result.push_back(newInterval);
    return result;
}