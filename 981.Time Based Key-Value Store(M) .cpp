#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Optimize
 *
 * Use map of map to achieve multiple key single value pair
 * Since the timestamp of set() will be strictly ascending, we can apply binary search for get()
 * We know binary search method is to get closer and closer to the target num, since the get() require to return
 * timestamp <= target_timestamp, we can keep assign the value if we found timestamp that is less than target_timestamp
 *
 * Time
 *  set: O(1)
 *  get: O(logN)
 *
 * Space: O(N)
 */
class TimeMap
{
public:
    unordered_map<string, vector<pair<string, int>>> table;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        table[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        string ans = "";
        if (!table.count(key))
            return ans;

        int left = 0, right = table[key].size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (table[key][mid].second <= timestamp)
            {
                ans = table[key][mid].first;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }
};
