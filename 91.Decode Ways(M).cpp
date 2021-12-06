#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution(FAIL)
 * *(DP)
 * 0. deal with '0' first, 跟前一個char綁定(if 前一個小於3)
 * 1. since every character can be isolate so init answer will be 1.
 * 2. during iterate check if
 *    1. if previous number is zero can not be combined
 *    2. if after combining is bigger 26 then can not be combined.
 *
 * Time: O(n)
 *
 * Edge Case:
 * 1. one element
 * 2. leading zero
 */
//int numDecodings(string s) {
//    if(s.size() == 1) return s[0]-'0' > 0 ? 1 : 0;
//    if(s[0] == '0') return 0;
//    int zero_check = 0, last_index=s.size();
//    vector<string> nums;
//    // 0.
//    for(int i=s.size()-1; i>0; i--){
//        if(s[i] == '0'){
//            if(s[i-1]-'0' >= 3 || s[i-1] == '0')
//                return 0;
//            else {
//                if((i+1) <= s.size()-1){
//                    nums.push_back(s.substr(i+1, last_index-i+1));
//                    last_index = i-2;
//                }
//                s.erase(i-1, 2);
//                i--;
//                last_index = i;
//                zero_check++;
//            }
//        }
//    }
//    if(last_index != 0)
//        nums.push_back(s.substr(0, last_index));
//    if(s == "")
//        return 1;
//    // if(nums.size() == 1 && nums[0] == "")
//    //     return zero_check;
//    string st = "";
//    int ans = 0;
//    int len_check = 0;
//    for(auto & it: nums)
//        cout << "nums: " << it << endl;
//    for(int index=0; index<nums.size(); index++) {
//        if(nums[index].size() == 1){
//            ans += 0;
//            len_check = 1;
//            continue;
//
//        }
//        st += s[0];
//        st += s[1];
//        vector<int> dp(nums[index].size(), 0);
//        dp[0] = 0;
//        dp[1] = nums[index][0]- '0' > 3 || stoi(st) > 26 ? 0 : 1;
//        // cout << "dp[1]: " << dp[1] << endl;
//        for (int i = 2; i <nums[index].size(); i++) {
//            st = "";
//            st += nums[index][i - 1];
//            st += nums[index][i];
//            if (stoi(st) <= 26)
//                dp[i] = dp[i-2] + 1 + dp[i-1];
//            else
//                dp[i] = dp[i-1];
//            // cout << "dp[i]: " << dp[i] << endl;
//            st = "";
//        }
//        // cout << "dp: " << dp[nums[index].size()-1] << endl;
//        ans += dp[nums[index].size()-1];
//    }
//    cout << "len_check: " << len_check << endl;
//    if(!zero_check)
//        return ans+1;
//    else
//    if(ans == 0 || len_check)
//        return ans+zero_check;
//    else
//        return ans+zero_check+1;
//
//}
/*
 * Optimize
 * *(DP, DFS  dp[i] = dp[i+1] + dp[i+2])
 * 1. (DP) backward tracking, if just one digit answer is 1, since dp need [i+1] and [i+2]
 *         create an array with s.size()+1
 * 2. (DFS)
 *
 * Time: O(n)
 * Space: O(n), can be better O(1) cause it only use previous two value.
 * Edge Case:
 * 1. leading zero
 *
 */
int numDecodings_dfs(string s, int i, vector<int> & dp){
    if(s[i] == '0') return 0;
    if(i == s.size()-1) return dp[s.size()-1];
    int res = numDecodings_dfs(s, ++i,dp);
    int number = (s[i] - '0') * 10 + (s[i + 1] - '0');
    if (number <= 26 && number >= 10)
        res += numDecodings_dfs(s, ++i, dp);
    dp[i] = res;

    return res;
}
int numDecodings(string s) {
    // DP Solution
    vector<int> dp(s.size()+1, 0);
    if(s[0] == '0') return 0;
    dp[s.size()] = 1;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] != '0')
            dp[i] += dp[i+1];
        if(i < s.size()-1) {
            int number = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (number <= 26 && number >= 10)
                dp[i] += dp[i + 2];
        }
    }
    return dp[0];

    // Space: O(1)
    if(s[0] == '0') return 0;
    int p1 = 1, p2 = 1;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == '0'){
            p2 = p1;
            p1 = 0;
        }
        if(i < s.size()-1 && s[i] != '0'){
            int number = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (number <= 26 && number >= 10) {
                int tmp = p1;
                p1 = p1 + p2;
                p2 = tmp;
            }else{
                p2 = p1;
            }
        }
        cout << "p1: " << p1 <<endl;
        cout << "p2: " << p2 <<endl;
    }
    return p1;
}
int main(){
    string s = "1234";
    numDecodings_dfs(s, 0, 1 ,0);
}

