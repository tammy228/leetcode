#include <vector>
using namespace std;
/*
 * My Solution
 * Use two pointer to point to where non-zero and zero at.
 * problem: [1,0] , [1, 0, 1] if the array is already done, the algo will still swap it.
 * modify: add "left<right" condition to make sure it did not swap right order
 */
void moveZeroes(vector<int> &nums)
{
    int left = 0, right = 0;
    while (left < nums.size())
    {
        while (left < nums.size() && nums[left] != 0)
        {
            left++;
        }
        while (right < nums.size() && nums[right] == 0)
        {
            right++;
        }
        if (left < nums.size() && right < nums.size() && left < right)
        {
            int temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;
        }
        if (left < right)
        {
            left++;
            right++;
        }
        else
        {
            right++;
        }
    }
}

/*
 * Optimize
 * Same idea with cleaner code
 */
void moveZeroes(vector<int> &nums)
{
    int left = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right])
        {
            swap(nums[left], nums[right]);
            left++;
        }
    }
}

/**
 * Idea: under left<right condition, swap(nums[left], nums[right])
 * left pointer: indicate zero position
 * right pointer: indicate non-zero position
 *
 * Time: O(N)
 * Space: O(1)
 */

void moveZeroes(vector<int> &nums)
{
    int left = 0, right = 0;
    while (right < nums.size())
    {
        while (left < nums.size() && nums[left] != 0)
            left++;
        while (right < nums.size() && nums[right] == 0)
            right++;
        if (left == nums.size() || right == nums.size())
            break;
        if (left < right)
            swap(nums[left], nums[right]);
        right++;
    }
}