#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/**
 * My Method
 * *Top k related problem must think of priority-queue(c++ default big->small)*
 * Max-heap
 * 1. Use map to store the frequent of each number
 * 2. Construct heap with frequent-number
 * 3. Pop k number from heap
 *
 * Time: O(N), N for nums.size()
 * Space: O(M), M is total count for different number
 */
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    vector<int> ans;
    for (int num : nums)
    {
        map[num]++;
    }
    priority_queue<pair<int, int>> pq;
    for (const auto &ele : map)
    {
        pq.push({ele.second, ele.first});
    }
    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
/**
 * Other Method
 * *Bucket sort, use 2d-array to implement, index means how many times it appears of each number
 *  value will be the number*
 * 1. Use map to store key:value -> number:freq
 * 2. Use 2d-array to store info
 * 3. Iterate 2d-array from right side and pop k element
 *
 * Time: O(M*k), M for total count of different number
 * Space: O(M)
 */
vector<int> topKFrequent2(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    vector<vector<int>> bucket(nums.size() + 1);
    vector<int> ans;
    for (int num : nums)
    {
        map[num]++;
    }
    for (const auto &ele : map)
    {
        bucket[ele.second].push_back(ele.first);
    }
    for (int i = bucket.size() - 1; i >= 0 && ans.size() < k; --i)
    {
        for (int num : bucket[i])
        {
            ans.push_back(num);
            if (ans.size() == k)
                break;
        }
    }
    return ans;
}
