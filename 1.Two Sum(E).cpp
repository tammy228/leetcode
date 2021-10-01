#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> um;
    int key;
    for(int i = 0; i < nums.size(); i++){
        key = nums[i];
        if(um.count(target - key) == 0){
            um[key] = i;
        }
        else{
            return { i, um[target - key]};
        }
    }
    return {};
}

