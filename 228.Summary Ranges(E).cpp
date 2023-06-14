#include <vector>
#include <string>
using namespace std;

/*
 * My Solution
 * 1. iterate the nums array, and check the next number to see if it's continuous
 *
 * Edge Case:
 * 1. since I put the first element into "range", we need to check if nums.size is bigger than 0
 *
 * Time:
 * O(N)
 *
 * Space:
 * O(1)
 */
vector<string> summaryRanges(vector<int>& nums) {
    if(nums.size() == 0) return {};
    vector<string> ans;
    string range = to_string(nums[0]);
    for(int i=0; i<nums.size(); i++){
        if(nums[i] != nums[i-1]+1){
            if(to_string(nums[i-1]) != range){
                range = range + "->" + to_string(nums[i-1]);
            }
            ans.push_back(range);
            range = to_string(nums[i]);
        }
    }
    if(to_string(nums[nums.size()-1]) != range){
        range = range + "->" + to_string(nums[nums.size()-1]);
    }
    ans.push_back(range);
    return ans;
}