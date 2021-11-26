#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * 1. create an n+1 size array put 1 in array if exist in nums
 * 2. check array which is zero
 *
 * Time: O(n)
 * Space: O(n)
 *
 */
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    vector<int> check(n+1, 0);
    for(int i=0; i<n; i++){
        check[nums[i]] = 1;
    }
    for(int i=0; i<check.size(); i++){
        if(check[i] == 0) return i;
    }
    return 0;
}
/*
 * Optimize
 * *(Sum)
 * 1. Sum(0-n) - Sum(array)
 */
//int missingNumber(vector<int>& nums){
//    int bigsum = (1+nums.size()) * nums.size() / 2;
//    for(int i=0; i<nums.size(); i++){
//        bigsum -= nums[i];
//    }
//    return bigsum;
//}