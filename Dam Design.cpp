#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int maxHeight(vector<int> positions, vector<int> heights){
    vector<int> ans;
    for(int i=1; i<positions.size(); i++){
        int gap = abs(positions[i] - positions[i-1]) - 1;
        int height_gap = abs(heights[i] - heights[i-1]);
        if(gap >= 1){
            if(height_gap < gap) {
                int tmp = gap-height_gap;
                int increase = tmp%2 == 0 ? tmp/2: tmp/2 +1;
                ans.insert(ans.end(), max(heights[i], heights[i-1]) + increase);
            }
            if(height_gap == gap)
                ans.insert(ans.end(), max(heights[i], heights[i-1]));
            if(height_gap == gap + 1)
                ans.push_back(max(heights[i], heights[i-1]) - 1);
            if(height_gap > gap)
                ans.push_back(min(heights[i], heights[i-1]) + gap);
        }
    }
    if(ans.empty())
        return 0;
    return *max_element(ans.begin(), ans.end());
}
//int main(){
//    vector<int> positions = {1,2,4,7};
//    vector<int> heights = {4,6,8,11};
//    int ans = maxHeight(positions, heights);
//    cout << ans << endl;
//}

