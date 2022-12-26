#include <iostream>
#include <unordered_map>
using namespace std;
int longestPalindrome(string s) {
    if(s.size() <= 1) return s.size();
    unordered_map<char, int> map;
    int ans = 0;
    int count = 0;
    for(int i=0; i<s.size(); i++){
        map[s[i]]++;
    }
    for(auto e : map){
        count ++;
        cout << e.first << e.second << endl;
        if(e.second % 2 == 0)
            ans += e.second;
        else
            ans += e.second-1;
    }
    if(count == 1)
        return s.size();
    if(ans == s.size())
        return ans;
    else return ans + 1;
}
//int main(){
//    string s = "abccccdd";
//    int test = longestPalindrome(s);
//    cout << test;
//}
/*
 * My Solution
 * Use map to store how many times each character appears
 * iterate the map to calculate the longest length of palindrome
 */
int longestPalindrome(string s) {
    unordered_map<char, int> map;
    int result = 0;
    int odd_count = 0;
    for(auto alpha: s){

        map[alpha]++;
    }
    for(auto item: map){
        if(item.second % 2 == 0){
            result += item.second;
        }else{
            result += item.second-1;
            odd_count = 1;
        }
    }
    if(odd_count)
        return result+1;
    else
        return result;
}
