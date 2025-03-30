#include <vector>
#include <unordered_map>
using namespace std;
/**
 * My Solution (Prefix Sum)
 * the brute force will be O(N^2), iterate the array and find all contiguous array that contain equal amount of zeros and ones.
 * -> therefore we should looking for O(N) or O(Nlogn)
 * In order to find the equal amount of zeros and ones, we need to keep track of current index of ones and zeros.
 * Ex: 1 1 1 0 0
 * index 4:
 * ones: 3
 * zeros: 2
 * On index 4, we know we need to find the min. len of subarray where the ones is one more the zeros.
 * Therefore, we can use a map to keep track of the diff between ones and zeros, by the time we get to index 4 we will know which prefix we should remove
 * Ex:
 * map[diff(ones - zeros)/index]:
 * 1:0
 * 2:1
 * 3:2
 *
 * Algo:
 * use a diff to keep track of the diff. of current index, while storing the diff. to map if there isn't one
 * Time: O(N)
 * Space: O(N)
 *
 * Edge: nums.size() == 1
 * [0,1]
 * -1:0
 * 0:1
 *
 * [0,1,1,1,1,1,0,0,0] index 8
 * diff:-1/0/1/2/
 * map:[-1,0]/[0,1]/[1,2],[2,3],[3,4],[4,5],
 * ans:0/1/0/2
 *
 */
int findMaxLength(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    unordered_map<int, int> map;
    int diff = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] == 1 ? diff++ : diff--;
        if (diff == 0)
            ans = i;
        if (!map.count(diff))
            map[diff] = i;
        ans = max(ans, i - map[diff]);
    }
    return ans % 2 == 0 ? ans : ans + 1;
}