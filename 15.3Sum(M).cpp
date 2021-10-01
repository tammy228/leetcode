#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
using namespace std;
// My Solution O(n^2)
//vector<vector<int>> threeSum(vector<int>& nums) {
//    vector<vector<int>> ans,tmp;
//    sort(nums.begin(), nums.end());
//    int x,two_sum;
//    set<vector<int>> duplicate;
//    for(int i=0; i<nums.size(); i++){
//        if(i>0 && nums[i]==nums[i-1])
//            continue;
//        x = nums[i];
//        two_sum = 0 - x;
//        set<int> two_sum_st;
//        for(int j=i+1; j<nums.size(); j++){
//            if(two_sum_st.count(two_sum-nums[j]) == 0)
//                two_sum_st.insert(nums[j]);
//            else
//                if(duplicate.count({x, two_sum-nums[j], nums[j]}) == 0){
//                    duplicate.insert({x, two_sum-nums[j], nums[j]});
//                    ans.push_back({x, two_sum - nums[j], nums[j]});
//                }
//        }
//    }
//    return ans;
//}

// Optimize
vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();
    if(n<3)
        return {};
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n-2; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j = i+1, k = n-1;
        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum==0){
                ans.push_back({nums[i], nums[j], nums[k]});
                while(j<k && nums[j] == nums[j+1]) j++;
                while(j<k && nums[k] == nums[k-1]) k--;
                j++;
                k--;
            }
            else if(sum > 0) k--;
            else j++;

        }
    }
    return ans;
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

