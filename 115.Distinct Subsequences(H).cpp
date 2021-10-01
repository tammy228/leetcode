#include <iostream>
#include <vector>
using namespace std;

// DP Solution O(n^2)
int numDistinct(string s, string t){
    int m = s.size();
    int n = t.size();
    vector<vector <unsigned int>> dp(n+1, vector<unsigned int>(m+1, 0));
    for(int i=0; i<=m; i++)
        dp[0][i] = 1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(t[i-1] == s[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            else
                dp[i][j] = dp[i][j-1];

    return dp[n][m];
}

//int main(){
//    string s = "babgbag";
//    string t = "bag";
//    int ans = numDistinct(s, t);
//    cout << ans;
//}
