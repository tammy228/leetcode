#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * 1. init i,j as INT_MAX
 * 2. iterate the array to check triplets
 * Edge Case:
 *   (1) nums.size() < 3
 *   (2) all elements are the same.
 */
bool increasingTriplet(vector<int>& nums) {
    if(nums.size() < 3) return false;
    int i = INT_MAX;
    int j = INT_MAX;
    for(int ind=0; ind<nums.size(); ind++){
        if(nums[ind] <= i)
            i = nums[ind];
        else if(nums[ind] <= j)
            j = nums[ind];
        else
            return true;
    }
    return false;
}

