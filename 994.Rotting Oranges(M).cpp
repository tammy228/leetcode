#include <queue>
using namespace std;

/*
 * My Solution
 * Use BFS
 * 1. insert all the rotten oranges into queue, and count the fresh oranges
 * 2. while iterating the rotten oranges, check if 4-direct adj. have fresh orange
 *    if true: push into queue, fresh--, turn it to rotten
 *    for every level, time++
 * 3. After traverse all the rotten oranges, check if fresh > 0
 *    if true: return -1
 *    else: return time
 *
 * Edge Case:
 * 1. No fresh orange at first: return 0
 * 2. fresh orange only: return -1
 *
 * Time:
 * O(mn): if all oranges are rotten
 *
 * Space:
 * O(mn): if all oranges are rotten
 */
void bfs(vector<vector<int>>& grid, queue<pair<int, int>> q,int& minutes, int& fresh){
    while(!q.empty()){
        int level = q.size();
        for(int i=0; i<level; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
                q.push({x + 1, y});
                grid[x+1][y] = 2;
                fresh--;
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
                q.push({x, y + 1});
                grid[x][y+1] = 2;
                fresh--;
            }
            if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                q.push({x - 1, y});
                grid[x-1][y] = 2;
                fresh--;
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                q.push({x, y - 1});
                grid[x][y-1] = 2;
                fresh--;
            }
        }
        minutes++;
    }
}
int orangesRotting(vector<vector<int>>& grid) {
    int minutes = -1, fresh = 0;
    queue<pair<int, int>> q;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++) {
            if (grid[i][j] == 1)
                fresh++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }
    if(!fresh)
        return 0;

    bfs(grid, q, minutes, fresh);


    // No rotten oranges
    if(fresh)
        return -1;
    else
        return minutes;
}