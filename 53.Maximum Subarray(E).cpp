#include<iostream>
#include<vector>
#include<climits>
using namespace std;
/*
 * My Solution
 * 1. There will be variable called "presum" which will accumulate the number while iterating the array.
 * 2. There will be another variable called "maxsum" which store the largest number of presum.
 * 3. while iterating the array:
 *    if (presum >= maxsum) maxsum = presum
 *    if (presum <= 0) presum = 0
 * Edge Case:
 * 1. if only one element, return nums[0]
 * Time: O(n)
 */
int maxSubArray(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int maxsum = INT_MIN;
    int presum = 0;
//    for(int i=0; i<nums.size(); i++){
//        presum += nums[i];
//        if(presum > maxsum) maxsum = presum;
//        // basically if presum is smaller than 0,
//        if(presum <= 0) presum = 0;
//    };
    // Using iterator for traversal (iterator is always faster)
    for(auto i: nums){
        presum += i;
        if (presum > maxsum) maxsum = presum;
        if(presum <= 0) presum = 0;
    }

    return maxsum;
}