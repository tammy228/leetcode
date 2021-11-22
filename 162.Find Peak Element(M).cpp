#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * *(Binary Search)
 * Edge Case
 * 1. One element
 *
 * Fail Case
 * 1. [1,6,5,4,3,2,1]
 */
//int findPeakElement(vector<int>& nums) {
//    int left=0, right=nums.size()-1;
//    if(nums.size() == 1) return 0;
//    while(left < right){
//        cout << "left: " << left << endl;
//        cout << "right:" << right << endl;
//        int middle = (left + right) / 2;
//        if(nums[left] < nums[middle])
//            left = middle;
//        else if(nums[left] > nums[middle])
//            right = middle;
//        else
//        if(right - left == 1){
//            if(nums[right] > nums[left])
//                return right;
//            else
//                return left;
//        }else{
//            if(nums[middle] < nums[right])
//                left = middle;
//            else
//                right = middle;
//        }
//    }
//    return 0;
//}
/*
 * Optimize
 * *(Binary Search)
 * 1. Compare mid-1, mid, mid+1
 * 2. stop:
 *    mid>mid-1 && mid>mid+1
 *    left-right == 1
 *
 * Edge Case
 * 1. One element
 * 2. Two element : Because at least need three elements to compare mid-1, mid , mid+1
 */
int findPeakElement(vector<int>& nums) {
    int left=0, right=nums.size()-1;
    if(nums.size() == 1) return 0;
    if(nums.size() == 2) return nums[0]>nums[1] ? 0 : 1;
    while(left < right){
        int mid = (left + right) / 2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
        else if(nums[mid+1] > nums[mid]) left = mid + 1;
        else if(nums[mid-1] >= nums[mid]) right = mid - 1;

        if(right - left == 1){
            if(nums[right] > nums[left])
                return right;
            else
                return left;
        }
    }
    if(nums[right] > nums[left])
        return right;
    else
        return left;
    return 0;
}