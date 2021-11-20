#include<iostream>
#include<vector>
using namespace std;
/*
 * 1. use *binary search to find leftmost
 * 2. use *binary search to find rightmost
 * *binary search: instead of returning middle item, keep searching leftmost(rightmost) until it's done.
 */
// rightBias: find rightmost
int binarySearch(vector<int>& nums, int left, int right, int target, int rightBias){
    int result = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(target == nums[mid]){
            result = mid;
            if (rightBias)
                left = mid + 1;
            else
                right = mid - 1;
        }else if(target > nums[mid]){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return result;
}
vector<int> searchRange(vector<int>& nums, int target) {
    if (!nums.size()) return {-1,-1};

    int leftmost = binarySearch(nums, 0, nums.size()-1, target, 0);
    int rightmost = binarySearch(nums, 0, nums.size()-1, target, 1);

    return {leftmost, rightmost};
}
//int main(){
//    vector<int> nums = {5,7,7,8,8,10};
//    vector<int> ans = searchRange(nums,8);
//    for(int i=0; i<ans.size(); i++)
//        cout << ans[i] << endl;
//}
