#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*
 * My Solution (FAIL)
 * *(HashTable)
 * 1. iterate every char store in hashtable
 * 2. check if exist in hashtable
 *    true: check longest len, if bigger replace len, else keep iterate
 *    false: store in hashtable
 *
 * Edge Case
 * 1. lower/ upper case
 * 2. Null string
 * 3. One Character
 */
//int lengthOfLongestSubstring(string s) {
//    if(s.size() == 0 || s.size() == 1)
//        return s.size();
//    unordered_map<char, int> map;
//    int ans=0,index=0;
//    for(int i=0; i<s.size(); i++){
//        if(map.count(s[i]) == 0){
//            map[s[i]] = i;
//        }else{
//            int biggest = map[s[i]] > index ? map[s[i]] : index;
//            if(i-biggest > ans)
//                ans = i - biggest;
//            index = map[s[i]] + 1;
//            map[s[i]] = i;
//            cout << "ans: " << ans << endl;
//            cout << "s[i]: " << s[i] << endl;
//            cout << "i: " << i << endl;
//            for(auto & it : map)
//                cout << it.first << it.second << endl;
//        }
//    }
//    return ans;
//}
/*
 * Optimize
 * *(Sliding Window(left, right pointer), unordered_set)
 * 1. sliding window contains unique characters
 * 2. During iterate the string,
 * if encounter duplicate character erase character from left until the characters in sliding window are unique.
 * 3. use "maxlen" to keep track of the maximum length of window
 *
 * Time: O(n)
 */
int lengthOfLongestSubstring(string s){
    unordered_set<char> set;
    int ans=0, left=0, right=0;
//    for(int right=0; right<s.size(); right++){
//        while (set.count(s[right])){
//            set.erase(s[left]);
//            left++;
//        }
//        set.insert(s[right]);
//        ans = max(ans, right-left+1);
//    }
    while(right < s.size()){
        if(set.count(s[right])){
            set.erase(s[left]);
            left++;
        }else{
            set.insert(s[right]);
            right++;
            ans = max(ans, right-left+1);
        }
    }

    return ans;
}
//int main(){
//    string s = "asdfiEWaAHRDFasdfhiu";
//    int ans = lengthOfLongestSubstring(s);
//    cout << "ans: " << ans << endl;
//}