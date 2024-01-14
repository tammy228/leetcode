#include <string>
#include <map>
#include <unordered_map>
using namespace std;

/*
 * Optimize
 *
 * Use map of map to achieve multiple key single value pair
 *
 * Time:
 *  set: std::map.insert() is O(logN), but if you have hint(in this case, if timestamp is in order), then O(1)
 *       since there are N elements. total : O(NlogN)
 *  get: O(logN) for single operation(binary search) , M times of get will be O(MlogN)
 *
 * Space: O(N)
 */
class TimeMap {
public:
    unordered_map<string, map<int, string>> table;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        table[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto iterator = table[key].upper_bound(timestamp);
        if (iterator != table[key].begin())
            return prev(iterator)->second;
        else
            return "";
    }
};
