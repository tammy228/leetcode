#include<vector>
using namespace std;
/*
 * My Solution
 * literally what binary search for
 * left, right pointers // left = 0, right = nums.size()-1
 * while (left ≤ right)
 * compare number and nums[middle]
 * if number is bigger → left move
 * else → right move
 *
 * Time: O(log n)
 * Space: O(1)
 */
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

