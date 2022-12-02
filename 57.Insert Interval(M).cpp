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
    vecotor<vecotr<int>> result;
    for(int i=0; i<intervals.size(); i++){

        if(newInterval[1] < intervals[i][0]){
            result.push_back(newInterval);
        }else if(intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
        }else{

        }
    }
}