#include <vector>
using namespace std;

/*
 * My Solution
 *
 * 1. Find the first positive element of position
 * 3 scenario
 * 1. no positive -> square all element and then reverse it
 * 2. all positive ->  square all element
 * 3. half positive half negative
 *      a. use two pointer to keep track of the negative number and positive number
 *      b. compare the number, smaller one output first and then forward the pointer
 *      c. repeat a. b. until two pointer reach the start/end of the array
 *
 * Time: O(N)
 * Space: O(1)
 */
//vector<int> sortedSquares(vector<int>& nums) {
//    int positive_start = nums.size() - 1;
//    vector<int> ans;
//    for (int i = 0; i < nums.size(); i++)
//    {
//        if (nums[i] >= 0)
//        {
//            positive_start = i;
//            break;
//        }
//    }
//    if (positive_start == 0)
//    {
//        for (int i = 0; i<nums.size(); i++)
//        {
//            ans.push_back(nums[i] * nums[i]);
//
//        }
//    }
//    else if (positive_start == nums.size() - 1 && nums[positive_start] < 0)
//    {
//        for (int i = nums.size() - 1; i >= 0; i--)
//
//        {
//            ans.push_back(nums[i] * nums[i]);
//        }
//    }
//    else
//    {
//        int negative_start = positive_start - 1;
//        while(negative_start >= 0 || positive_start < nums.size())
//        {
//            if (negative_start < 0)
//            {
//                ans.push_back(nums[positive_start] * nums[positive_start]);
//                positive_start++;
//            }
//            else if (positive_start >= nums.size())
//            {
//                ans.push_back(nums[negative_start] * nums[negative_start]);
//                negative_start--;
//            }
//            else if (abs(nums[negative_start]) <= abs(nums[positive_start]))
//            {
//                ans.push_back(nums[negative_start] * nums[negative_start]);
//                negative_start--;
//            }
//            else
//            {
//                ans.push_back(nums[positive_start] * nums[positive_start]);
//                positive_start++;
//            }
//        }
//    }
//    return ans;
//}

/*
 * Optimize
 *
 * Same idea of above solution, only change to output largest to smallest, and put the ans backwards
 *
 * Time: O(N)
 * Space: O(1)
 */

vector<int> sortedSquares(vector<int>& nums) {
    int negative = 0, positive = nums.size() - 1;
    int size = nums.size() - 1;
    vector<int> ans (nums.size() , 0);
    while(negative <= positive)
    {
        if(abs(nums[negative]) >= abs(nums[positive]))
        {
            ans[size--] = nums[negative] * nums[negative];
            negative++;
        }
        else
        {
            ans[size--] = nums[positive] * nums[positive];
            positive--;
        }
    }
    return ans;
}