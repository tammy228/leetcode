#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * My Solution(FAIL)
 * Sort first and accumulate left side compare to right side
 */
//bool canPartition(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//    int rightside = nums[nums.size()-1];
//    int leftside = accumulate(nums.begin(), nums.end()-1, 0);
//    int index = 0;
//    while(leftside > rightside){
//        leftside -= nums[index];
//        rightside += nums[index];
//        index++;
//    }
//    if(leftside == rightside)
//        return true;
//    else
//        return false;
//}
/*
 * Optimize
 *
 * Use set to store every combination of the array
 *
 * **Set.insert is much slower than vector and can not control the space complexity
 * **Use dp instead of set
 * Time:
 * O(N*sum(nums))
 *
 * Space:
 * O(too....big)
 * 1 -> 1
 * 2 -> 3
 * 3 -> 7
 * 4 -> 15
 * N -> 1 + (N-1) *2^(N-2)
 */
bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;


    vector<bool> dp(total/2+1, false);
    dp[0] = true;

    for(auto & n : nums){
        // Need to use another set insert, cause can't add set while iterating
        for(int i=total/2; i>=n; i--){
            if(dp[i-n]) dp[i] = true;
            if(dp[total/2]) return true;
        }
    }
    return dp[total/2];
}