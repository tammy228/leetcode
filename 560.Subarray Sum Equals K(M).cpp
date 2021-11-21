#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
 * My Solution
 * 1. 在一個iterate 中, 紀錄各種不同的prefixSum 出現的次數
 * (Use hashtable to record)
 * 2. 當totalsum - k == prefixSum 就等於找到combination
 *
 * Edge Case
 *  (1) Only one element
 */
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixsum_map;
    prefixsum_map[0] = 1;
    int sum=0,result=0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(prefixsum_map.count(sum-k))
            result += prefixsum_map[sum-k];
        prefixsum_map[sum] ++;
    }
    return result;
}
