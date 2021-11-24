#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;
/*
 * My Solution
 * *(unordered_set)
 * 1. iterate vector and store item in set
 *    if set.count() == true: return true
 *    else keep going
 *
 * Time: O(n)
 *
 * Edge Case:
 * 1. One element
 */
bool containsDuplicate(vector<int>& nums) {
    if(nums.size() == 1) return false;
    unordered_set<int> set;
    for(int i=0; i<nums.size(); i++){
        if(set.count(nums[i]))
            return true;
        else
            set.insert(nums[i]);
    }
    return false;
}