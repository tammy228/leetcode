#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int trap(vector<int>& height) {
    int ans = 0;
    int n = height.size();
    if(n < 2)
        return 0;
    else {
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        maxLeft[0] = 0;
        maxLeft[1] = height[0];
        maxRight[n - 1] = 0;
        maxRight[n - 2] = height[n - 1];
        for (int i = 2; i < n; i++)
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
        for (int i = n - 3; i > 0; i--)
            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
        for (int i = 0; i < n; i++) {
            int lower = min(maxRight[i], maxLeft[i]);
            if (lower > height[i])
                ans += lower - height[i];
        }
    }
    return ans;
}
//int main(){
//    vector<int> height  = {0,1,0,2,1,0,1,3,2,1,2,1};
//    int ans = trap(height);
//    cout << ans;
//}
