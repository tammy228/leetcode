#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
// My Solution: Totally not work out, just pass half of the input
//bool canPartitionKSubsets(vector<int>& nums, int k) {
//    bool ans;
//    int n = k;
//    int same_value = 1;
//    for(int i=1; i<nums.size(); i++)
//        if(nums[i] == nums[i-1])
//            same_value++;
//
//    if(same_value % k == 0 and same_value == nums.size()) return true;
//    sort(nums.begin(), nums.end());
//    int left = 0;
//    int right = nums.size()-2;
//    int sum = nums[nums.size()-1];
//    while(nums[right] == sum) right--;
//    while(nums[left] + nums[right] > sum and left != right){
//        sum += nums[left];
//        left++;
//    }
//    cout << "left: "<< left <<endl;
//    cout << "right: "<< right << endl;
//    if(nums[left] + nums[right] == sum){
//        k--;k--;right--;
//        for(int i=left+1; i<right; i++){
//            if(nums[i] + nums[right] == sum) {
//                right--;
//                k--;
//            }
//        }
//    }
//    cout << k << endl;
//    if(!k || (k%n == 0 and k!=n))
//        ans =  true;
//    else
//        ans = false;
//    if(ans)
//        return true;
//    else{
//        k = n;
//        left = 0;
//        right = nums.size()-2;
//        sum = nums[nums.size()-1];
//        while(nums[left] + nums[right] > sum and left != right){
//            sum += nums[left];
//            left++;
//        }
//        cout << "left: "<< left <<endl;
//        cout << "right: "<< right << endl;
//        if(nums[left] + nums[right] == sum){
//            k--;k--;right--;
//            for(int i=left+1; i<right; i++){
//                if(nums[i] + nums[right] == sum) {
//                    right--;
//                    k--;
//                }
//            }
//        }
//        cout << "post k: "<<  k << endl;
//        if(!k || k%n == 0)
//            return true;
//        else
//            return false;
//    }
//}

// Optimize: Backtracking
/*
 * 1. edge cases: sum(nums) % k != 0
 * 2. Solution: recursion + backtracking
 *  2.1 make sure sum(nums) % k == 0 or return false
 *  2.2 backtrack all the possibilities
 */
// MUST USE "Past by Reference" or it will time limit
// Time Complexity: O(k!(k^N))
bool backtrack(vector<int>& nums, vector<int>& used, int subsetSum, int bucketSum, int k, int iterateStart){
    // Finish Condition
    if(k == 1)
        return true;
    // If we did find a subset
    if(bucketSum == subsetSum)
        return backtrack(nums, used, subsetSum, 0, --k, 0);

    for(int i=iterateStart; i<nums.size(); i++){
        if(bucketSum + nums[i] > subsetSum) continue;
        if(!used[i]) {
            used[i] = 1;
            if (backtrack(nums, used, subsetSum, bucketSum + nums[i], k, i + 1)) return true;
            used[i] = 0;
        }
    }
    return false;
}
bool canPartitionKSubsets(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> used(nums.size(), 0);
    if(sum % k != 0)
        return false;
    return backtrack(nums,used, sum / k, 0, k, 0);
}
//int main(){
//    int k = 3;
//    vector<int> nums = {129,17,74,57,1421,99,92,285,1276,218,1588,215,369,117,153,22};
//    bool ans = canPartitionKSubsets(nums, k);
//    cout <<"ans: "<< ans << endl;
//}