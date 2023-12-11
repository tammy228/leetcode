#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int counter = 0, left = 0, right = 0, ans = INT_MAX;
    while(right < nums.size())
    {
        counter += nums[right];
        right++;
        while(counter >= target)
        {
            ans = min(ans, right-left);
            counter -= nums[left];
            left++;
        }
    }
    return ans == INT_MAX ? 0 : ans;
}