#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * My Solution
 * use ordered_map to store info, first: the number of "target - nums[i]", second: the index of that nums[i]
 *
 * 1. while iterating the nums, store the info into map
 * 2. meanwhile, check if nums[i] exists in map.
 *    if true: return {i, maps[nums[i]]}
 *
 * Edge Case: Nope
 *
 * Time: O(n)
 * Space: O(n)
 */
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i=0; i<nums.size(); i++){
        if(map.find(nums[i]) != map.end())
            return {i, map[nums[i]]};
        map[target-nums[i]] = i;
    }
    return {};
}

