#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * My Solution
 * iterate string s, with each start position, take sub_s = s.substr(start_position, p.size())
 * check sub_s and p if they are anagram
 *
 * Time: O(NM): N = s.size(), M = p.size()
 * Space: O(26)
 */
//bool isAnagram(string s, string p)
//{
//    if(s.size() != p.size())
//        return false;
//    int count[26] = { 0 };
//    for(int i=0; i<s.size(); i++)
//    {
//        count[s[i] - 'a']++;
//        count[p[i] - 'a']--;
//    }
//
//    for(auto &number : count)
//    {
//        if(number != 0)
//            return false;
//    }
//    return true;
//}
//vector<int> findAnagrams(string s, string p) {
//    vector<int> ans;
//    for(int i=0; i<s.size(); i++)
//    {
//        string sub_s = s.substr(i, p.size());
//        if(isAnagram(sub_s, p))
//            ans.push_back(i);
//    }
//    return ans;
//}

/*
 * Optimize
 * Using sliding window, store p value first, and compare value according to sliding window
 *
 * Note: std::vector and std::array works on operator '==' , it will compare to size first, it will return false if size is different
 * if not it will compare contents element by element
 *
 * Time: O(N): N == s.size()
 * Space: O(2*26) = O(1)
 */
vector<int> findAnagrams(string s, string p) {
    vector<int> goal(26, 0), curr(26, 0), ans;

    // store p value to vector
    for(int i=0; i<p.size(); i++)
    {
        goal[p[i] - 'a']++;
    }

    for(int i=0; i<s.size(); i++)
    {
        curr[s[i] - 'a']++;
        if(i >= p.size())
            curr[s[i - p.size()] - 'a']--;
        if(curr == goal)
            ans.push_back(i - p.size() + 1);
    }
    return ans;
}

