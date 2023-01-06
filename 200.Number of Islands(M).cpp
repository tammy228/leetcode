#include <queue>
using namespace std;

/*
 * My Solution
 * Use bfs to traverse all "1"s
 * use set to store visited '1'
 * * unordered container can't use pair, because it uses std::hash to computing key value,
 * * and there is no std::hash for std::pair in C++ library.
 */
void bfs(vector<vector<char>>& grid, queue<pair<int, int>>& q, set<pair<int, int>>& seen){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(seen.count({x, y}))
            continue;
        // right
        if(x+1 < grid.size() && grid[x+1][y] == '1'){
            q.push({x+1, y});
        }
        // up
        if(y+1 < grid[0].size() && grid[x][y+1] == '1'){
            q.push({x, y+1});
        }
        if(x-1 >= 0 && grid[x-1][y] == '1'){
            q.push({x-1, y});
        }
        if(y-1 >= 0 && grid[x][y-1] == '1'){
            q.push({x, y-1});
        }
        seen.insert({x, y});
    }
}

int numIslands(vector<vector<char>>& grid) {
    set<pair<int, int>> seen;
    queue<pair<int, int>> q;
    int ans = 0;
    // store all the '1' into q
    for(int i=0; i< grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j] == '1' && !seen.count({i, j})) {
                q.push({i, j});
                bfs(grid, q, seen);
                ans++;
            }
        }
    }
    return ans;
}