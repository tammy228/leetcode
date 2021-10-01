#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(int i=1; i<n; i++){
        if(intervals[i][0]<=ans.back()[1] and intervals[i][1] > ans.back()[1])
            ans.back()[1] = intervals[i][1];
        if(intervals[i][0] > ans.back()[1])
            ans.push_back(intervals[i]);
    }
    return ans;
}
//int main(){
//    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
//    vector<vector<int>> ans = merge(intervals);
//    for(auto IE=ans.begin(); IE!=ans.end(); IE++) {
//        for (auto it = (*IE).begin(); it != (*IE).end(); it++)
//            cout << (*it);
//        cout << "\n";
//    }
//}
