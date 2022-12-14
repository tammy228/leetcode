#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
 * My Solution
 * Apply "Two Sum" for N times
 *
 * Time:
 * O(N^2): where N = nums.size()
 *
 * Space:
 * O(N): where N = nums.size()
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int target = INT_MIN;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        vector<int> combinations;
        if(target != -nums[i]) {
            unordered_set<int> set;
            target = -nums[i];
            int tmp = INT_MIN;
            for (int j = i+1; j < nums.size(); j++) {
                if(tmp != nums[j]) {
                    if (set.find(nums[j]) != set.end()) {
                        tmp = nums[j];
                        combinations.push_back(nums[j]);
                        combinations.push_back(target - nums[j]);
                        combinations.push_back(nums[i]);
                        result.push_back(combinations);
                        combinations.clear();
                    }
                    set.insert(target - nums[j]);
                }
            }
        }
    }
    return result;
}


/*
 * Optimize
 * 1. Sort the array to prevent duplicate problem
 * 2. Use "Two pointers" to find sum, during the finding if pointers point to same value as before, then shift it.
 *
 * Time:
 * O(N^2)
 *
 * Space:
 * O(1)
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    // 1.
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size()-2; i++){
        // prevent use duplicate of first number
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        int left = i + 1;
        int right = nums.size()-1;
        // 2.
        while(left < right){
            int threeSum = nums[i] + nums[left] + nums[right];
            if(threeSum > 0) {
                right--;
            }else if(threeSum < 0) {
                left++;
            }else{
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                // only check one of the pointer, because the outer while loop is going to check the other pointer
                // always remember if there is another while loop inside while loop, be careful with the condition
                while(left < right && nums[left] == nums[left-1]) left++;
            }
        }
    }
    return result;
}

//int main(){
//    vector<int> nums = {-1,0,1,2,-1,-4};
//    vector<vector<int>> ans = threeSum(nums);
//    for(auto IE=ans.begin();IE<ans.end();IE++)
//    {
//        for (auto it=(*IE).begin();it<(*IE).end();it++)
//        {
//            cout<<*it<<" ";
//        }
//        cout<<endl;
//    }
//}

