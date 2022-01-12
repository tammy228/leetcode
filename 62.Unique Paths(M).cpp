#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * *(DP, DFS)
 * *(DFS will cause time limit)
 */
int uniquePaths_dfs(int m, int n, int x, int y, vector<vector<int>> & dp){
    if(x > m || y > n)
        return 0;

    // if the cell is already calculated, return it's value.
    if(dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = uniquePaths_dfs(m , n, x+1, y, dp) + uniquePaths_dfs(m , n, x, y+1, dp);

    return dp[x][y];

}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp (m+1, vector<int>(n+1,-1));
    dp[m][n] = 1;
    return uniquePaths_dfs(m, n, 0, 0, dp);;
}
