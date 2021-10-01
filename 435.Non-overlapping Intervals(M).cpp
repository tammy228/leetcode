#include <iostream>
#include <vector>
using namespace std;
// My Solution: O(n*logn)
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int count = 0;
    int index = 0;
    for(int i=1; i<intervals.size(); i++){
       // Ex: [1,2], [1,3] -> 取[1,2]
       if(intervals[index][0] == intervals[i][0] ){
           count ++;
           if(intervals[index][1] > intervals[i][1])
               index  = i;
       }
       // Ex: [1,4], [2,3] -> 取[2,3]
       // Ex: [1,4], [2,6] -> 取[1,4]
       if(intervals[index][0] < intervals[i][0] && intervals[i][0] < intervals[index][1]){
           count ++;
           if(intervals[i][1] <= intervals[index][1])
               index  = i;
       }
       if(intervals[i][0] > intervals[index][1])
           index = i;
    }
    return count;
}