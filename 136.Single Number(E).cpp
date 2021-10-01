#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// My Solution
//int singleNumber(vector<int>& nums) {
//        unordered_map<int, int> umap;
//        int key;
//        for(int i=0; i< nums.size(); i++){
//            if(umap.count(nums[i]) == 0){
//                umap[nums[i]] = nums[i];
//                key = nums[i];
//            }else
//                umap.erase(nums[i]);
//
//        }
//        auto iter=umap.begin();
//        return iter->first;
//}
// Optimize
int singleNumber(vector<int> &nums){
    int ans = nums[0];
    for(int i=1; i<nums.size(); i++){
        ans ^= nums[i];
    }
    return ans;
}


//int main(){
//    vector<int> nums = {2, 2, 1};
//    int ans = singleNumber(nums);
//    cout << ans << endl;
//}
