#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;
/*
 * My Solution
 * 1. create a dp array to store every character that can or cannot be found in dictionary
 * 2. dp condition: if wordDict[i].size() != string[i:j] -> not the same
 *
 */
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1, false);
    dp[s.size()] = true;
//    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    for(int i=s.size(); i>=0; i--){
        for(int j=0; j<wordDict.size(); j++){
            if((i+wordDict[j].size()) <= s.size() && s.substr(i, wordDict[j].size()) == wordDict[j])
                dp[i] = dp[i+wordDict[j].size()];
            if (dp[i])
                break;
        }
    }
    return dp[0];
}

