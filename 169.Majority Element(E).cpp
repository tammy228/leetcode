#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * My Solution
 * 1. using HashMap to keep track of every element
 *
 * Time: O(n)
 * Space: O(n)
 */
//int majorityElement(vector<int>& nums) {
//    if(nums.size() == 1)
//        return nums[0];
//    int majority = nums.size() / 2;
//    unordered_map<int, int> umap;
//    for(int i=0; i<nums.size(); i++){
//        if(umap.count(nums[i]) == 0)
//            umap[nums[i]] = 1;
//        else{
//            umap[nums[i]]++;
//            if(umap[nums[i]] > majority)
//                return nums[i];
//        }
//    }
//    return 0;
//}
/*
 * Optimize(Boyer-Moore algo)
 * 1. keep track of the current number count, if same count++, if not count--
 *    不管每個number的出現次數，只用出現的次數來找majority. 就不用管到底有無sort
 *
 * Time: O(n)
 * Space: O(1)
 */
int majorityElement(vector<int>& nums) {
    int count = 1;
    int majority = nums[0];
    for(int i=1; i<nums.size(); i++){
        if(nums[i] == majority)
            count++;
        else
            count--;
        if(count == 0) {
            majority = nums[i];
            count = 1;
        }
    }
    return majority;
}
