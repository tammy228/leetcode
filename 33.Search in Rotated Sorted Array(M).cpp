#include <iostream>
#include <vector>
using namespace std;
/* My Solution(Fail):
 * 1. find k
 * 2. reorder &nums to sorted array
 * 3. apply binary search
 * Edge Case: Only one element
 * Problems: [1,3] it will error if it is sorted.
 */
// int binarySearch(vector<int> &new_nums, int target){
//     int left=0, right=new_nums.size();
//     int result = -1;
//     while(left <= right) {
//         int middle = (left + right) / 2;
//         if (new_nums[middle] > target)
//             right = middle - 1;
//         else if (new_nums[middle] < target)
//             left = middle + 1;
//         else {
//             result = middle;
//             break;
//         }
//     }
//     return result;
// }
// int search(vector<int>& nums, int target) {
//     if(nums.size() == 1)
//         return binarySearch(nums, target);
//     int biggest = INT_MIN;
//     int index;
//     // 1.
//     for(int i=0; i<nums.size(); i++){
//         if(nums[i] > biggest) {
//             biggest = nums[i];
//             index = i;
//         }
//     }
//
//     // 2.
//     vector<int> new_nums(nums.size());
//     // new_nums[0~index]
//     for(int i=index+1, tmp=0; i<nums.size(); i++, tmp++)
//         new_nums[tmp] = nums[i];
//     // new_nums[index~nums.size()]
//     for(int i=0, tmp=nums.size()-index-1; i<=index; i++, tmp++)
//         new_nums[tmp] = nums[i];
//
//     int result = binarySearch(new_nums, target);
//     if(result != -1)
//         if(index)
//             return result+index+1;
//         else
//             return result+index;
//     else
//         return result;
// }
/*
 * Optimize
 * 1. locate middle element in the right part array or left part array
 * 2. find the rule when the left and right pointer move
 */
int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;

        // 1.
        // rotated left portion
        else if (nums[mid] >= nums[left])
        {
            // 2.
            if (target > nums[mid] || target < nums[left])
                left = mid + 1;
            else
                right = mid - 1;
        }
        // rotated right portion
        else
        {
            // 2.
            if (target < nums[mid] || target > nums[right])
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    return -1;
}