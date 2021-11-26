#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * *(DP)
 * 1. init first row and first column as 0
 * 2. if 'a' == 'b' max(dp[i-1], dp[j-1]) +1
 *    else max(dp[i-1], dp[j-1])
 *
 * Time: O(m*n): m: text1.size(), n: text2.size()
 * Space:  O(m*n)
 *
 * Edge Case:
 * 1. one text is NULL: return 0
 * 2. both NULL: return 0
 */
int longestCommonSubsequence(string text1, string text2) {
    if(text1.size() == 0 || text2.size() == 0) return 0;
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
    // 2.
    for(int i=0; i<text1.size(); i++){
        for(int j=0; j<text2.size(); j++){
            if(text1[i] == text2[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    return dp[text1.size()][text2.size()];
}

