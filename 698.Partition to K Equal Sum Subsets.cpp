#include <vector>
#include <iostream>
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
bool canPartitionKSubsets(vector<int>& nums, int k) {

}
int main(){
    int k = 2;
    vector<int> nums = {1,1,1,1,9};
    bool ans = canPartitionKSubsets(nums, k);
    cout <<"ans: "<< ans << endl;
}