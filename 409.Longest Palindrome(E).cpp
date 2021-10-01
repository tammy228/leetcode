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