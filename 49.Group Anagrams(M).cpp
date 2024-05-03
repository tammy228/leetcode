#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
/*
 * My Solution
 * *(Anagram string will be same after sort)
 * *(Use sorted string as key, original string as value)
 * 1. Hastable
 *    key: sorted string
 *    value: original string
 * 2. iterate the map and put it to vector<vector<string>>
 *
 * Time: m*nlogn
 *       m: the size of input vector<string>
 *       nlogn: sort algo
 * Space: O(m)
 * Edge Case
 * 1. Empty: return empty
 */
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> map;
    // 1.
    for (auto &str : strs)
    {
        string ori_str = str;
        sort(ori_str.begin(), ori_str.end());
        map[ori_str].push_back(str);
    }
    vector<vector<string>> ans;
    // 2.
    for (auto &it : map)
    {
        ans.push_back(it.second);
    }
    return ans;
}