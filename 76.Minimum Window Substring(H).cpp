#include <unordered_map>
#include <climits>
#include <iostream>
using namespace std;
/*
 * My Solution(Fail, Time Limit Exceed)
 *
 * 1. Use map to store how many times of each char. appear
 * 2. generate a sliding window of (size "t"- size"s") to scan "s"
 *    while scanning minus the number in map
 *    if(total(map)) == 0 -> return string
 *    else -> return ""
 */
//string minWindow(string s, string t) {
//    if(t.size() > s.size()) return "";
//    unordered_map<char, int> map;
//    for(char s : t)
//        map[s]++;
//
//
//    for(int i=t.size(); i<=s.size(); i++){
//        int j=0;
//        for(j=0; j<s.size()-i+1; j++){
//            string temp = s.substr(j, i);
//            unordered_map<char, int> copy = map;
//            for(auto ch : temp){
//                if(copy.count(ch))
//                    copy[ch]--;
//            }
//            bool total = true;
//            for(auto ele : copy)
//                if(ele.second > 0)
//                    total = false;
//            if(total)
//                return s.substr(j, i);
//        }
//    }
//    return "";
//}
/*
 * Optimize
 * Use linear search, keep expand sliding window when the substr haven't matched all the char. in target
 * As soon as match all the char., move the left pointer until not match, update the length as well.
 *
 * Time:
 * O(M+N): M for s.size(), N for t.size(), to be more accurate will be 2M+N
 *
 * Space:
 * O(N): N for t.size()
 */
string minWindow(string s, string t) {
    if(t.size() > s.size()) return "";
    unordered_map<char, int> map;
    for(char s : t){
        map[s]++;
    }

    int left=0, right=0;
    int shortest_length = INT_MAX;
    int valid_count = map.size();
    int start = 0;
    while(right < s.size()){
        map[s[right]]--;
        if(map[s[right]] == 0)
            valid_count--;

        while(valid_count == 0){
            if (right - left + 1 < shortest_length) {
                shortest_length = right - left + 1;
                start = left;
            }
            map[s[left]]++;
            if(map[s[left]] > 0)
                valid_count++;
            left++;
        }
        right++;
    }
    if(shortest_length != INT_MAX)
        return s.substr(start, shortest_length);
    else
        return "";
}