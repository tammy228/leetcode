#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int majorityElement(vector<int>& nums) {
    if(nums.size() == 1)
        return nums[0];
    int majority = nums.size() / 2;
    unordered_map<int, int> umap;
    for(int i=0; i<nums.size(); i++){
        if(umap.count(nums[i]) == 0)
            umap[nums[i]] = 1;
        else{
            umap[nums[i]]++;
            if(umap[nums[i]] > majority)
                return nums[i];
        }
    }
    return 0;
}

