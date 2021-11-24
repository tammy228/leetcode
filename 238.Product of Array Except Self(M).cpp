#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * 1. left->right 連乘
 * 2. right->left 連乘
 * 3. 1. * 2.
 * Ex: [1,2,3,4]
 * 1. [1,1,2,6]
 * 2. [24,12,4,1]
 * ans:[24,12,8,6]
 */
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    int previous = 1;
    // 1.
    for(int i=1; i<nums.size(); i++)
        result[i] = result[i-1] * nums[i-1];
    // 2. 3.
    for(int i=nums.size()-2; i>=0; i--) {
        int tmp = previous * nums[i+1];
        result[i] = result[i] * tmp;
        previous = tmp;
    }
    return result;
}
//int main(){
//    vector<int> nums = {1,2,3,4};
//    vector<int> result = productExceptSelf(nums);
//}

