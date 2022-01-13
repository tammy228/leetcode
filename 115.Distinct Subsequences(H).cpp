#include <iostream>
#include <vector>
using namespace std;

/*
 * Method(DP(for-loop, recursive))
 * 1. use array to store how many ways can 's' be matched to 't'
 * 2. dp[i][j] = number of subseq of s[1:i]  and t[1:j]
 *
 * Edge:
 * 1. s=NULL  return 0, since it has no character to match
 * 2. t=NULL  return 1
 * Time: O(n * m), where n=s.size(), m=t.size()
 * Space: O(n * m)
 */

int dfs(vector<vector<int>>& dp, string s, string t, int i, int j){
    if(i == s.size())
        return 0;
    if(j == t.size())
        return 1;
    // Must have this condition, or will cause time limit. This condition is precisely dp array for
    if(dp[i][j] != -1)
        return dp[i][j];

    if(s[i] == t[j])
        dp[i][j] = dfs(dp, s, t, i+1, j+1) + dfs(dp, s, t, i+1, j);
    else
        dp[i][j] = dfs(dp, s, t, i+1, j);
    return dp[i][j];

}
int numDistinct(string s, string t){
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // for-loop
    for(int i=0; i<=m; i++)
        dp[0][i] = 1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(t[i-1] == s[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            else
                dp[i][j] = dp[i][j-1];

    return dp[n][m];

    // recursive
    return dfs(dp, s, t, 0, 0);
}

//int main(){
//    string s = "babgbag";
//    string t = "bag";
//    int ans = numDistinct(s, t);
//    cout << ans;
//}
