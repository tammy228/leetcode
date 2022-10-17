#include<unordered_map>
#include<string>
using namespace std;
/*
 * My Solution
 * 1. use a map to store the times of numbers, compare the map to the second string
 * 2. check the map if it's empty
 *
 * Edge Case:
 * 1. remember to check if the number in the map is less than zero, still return false
 *
 * Time: O(s+t) // n = max(s.size(), t.size())
 * Space: O(s+t)
 *
 * Improvement
 * 1. won't need map iteration, and map.count() in second for-loop
 *    use map[ch]--, and check if the value < 0, will do the same effect.
 *
 * Optimize(Space comp.)
 * 1. use sort.
 *    return sort(s) == sort(t);
 *
 * Time: O(n*log n)
 * Space: no
 *
 */
bool isAnagram(string s, string t) {
    unordered_map<char, int> map;
    for(char ch : s)
        map[ch]++;

    for(char ch : t) {
        // Improve
        map[ch]--;
        if(map[ch] < 0) return false;
        // My Solution
//        if (!map.count(ch) && map[ch] > 0)
//            return false;
//        else
//            map[ch]--;
    }
    //won't need
//    for(auto &it: map)
//        if (it.second != 0)
//            return false;
    return true;
}
