#include <iostream>
#include <vector>
using namespace std;
/*
 * My Solution
 * * (Binary Search)
 * 1. Compare left pointer and middle
 *    left < mid: left = mid
 *    left > mid: right = mid
 *    stop: left == mid || In the ascending subarray
 * Edge Case
 *  (1) One element
 *  (2) [2,1]
 *  (3) [3, 1, 2]
 */
int findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    int min_num = INT_MAX;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        // normal
        if (nums[right] >= nums[left])
        {
            return min(min_num, nums[left]);
        }
        else // rotated
        {
            if (nums[mid] >= nums[left])
                left = mid + 1;
            else
            {
                right = mid - 1;
                min_num = min(min_num, nums[mid]);
            }
        }
    }
    return min(min_num, nums[left]);
}
