#include<vector>
#include<queue>
#include<climits>
using namespace std;

/*
 * My Solution
 * bfs + dp
 * (不用traverse 所有的element, dp初始時在0的位置直接給0, 1的位置給INT_MAX
 *  從0的地方做broadcast(BFS))
 * 1. init dp
 * 2. push position of 0 into queue
 * 3. if dp[x][y] + 1 < dp[i][j](i, j 為上下左右的位置) -> dp[i][j] = dp[x][y] + 1(更新位置)
 * 4. push dp[i][j] into queue
 *
 * Time:
 * O(row * col)
 * Space:
 * O(row * col)
 */
void bfs(vector<vector<int>>& mat, vector<vector<int>>& dp){
    queue<pair<int, int>> q;
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat[0].size(); j++) {
            if(mat[i][j] == 0) {
                q.push(make_pair(i, j));
                dp[i][j] = 0;
            }
        }

    while(!q.empty()){
        pair<int, int> element = q.front();
        int x = element.first;
        int y = element.second;
        q.pop();
        if (x - 1 >= 0 && dp[x][y] + 1 < dp[x - 1][y]) {
            q.push(make_pair(x - 1, y));
            dp[x - 1][y] = dp[x][y] + 1;
        }
        if (x + 1 < dp.size() && dp[x][y] + 1 < dp[x + 1][y]) {
            q.push(make_pair(x + 1, y));
            dp[x + 1][y] = dp[x][y] + 1;
        }
        if (y - 1 >= 0 && dp[x][y] + 1 < dp[x][y - 1]) {
            q.push(make_pair(x, y - 1));
            dp[x][y - 1] = dp[x][y] + 1;
        }
        if (y + 1 < dp[0].size() && dp[x][y] + 1 < dp[x][y + 1]) {
            q.push(make_pair(x, y + 1));
            dp[x][y + 1] = dp[x][y] + 1;
        }
    }
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> dp(mat.size(), vector<int> (mat[0].size(), INT_MAX));
    bfs(mat, dp);
}