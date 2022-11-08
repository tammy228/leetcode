#include<vector>
#includ<queue>
using namespace std;
/*
 * My Solution
 * BFS
 * 1. Find four directions of starting pixels and add it to a queue.
 * 2. while queue ≠ empty():
 *      1. pop elements
 *      2. check four directions, and add ori_colorid pixels into queue.
 *      3. plus the number by 1 // WRONG! Should be fill with the number that the question gave.
 *      4. BFS()
 * Edge Case:
 * 1. if [sr, sc] are the new color, don't need to fill.
 */
void check_4dir(vector<vector<int>>& image, int x, int y, queue<pair<int, int>> &queue, int color, int ori_color){
    if(x-1>=0 && image[x-1][y] == ori_color){
        queue.push(make_pair(x-1, y));
        image[x-1][y] = color;
    }
    if(x+1<image.size() && image[x+1][y] == ori_color){
        queue.push(make_pair(x+1, y));
        image[x+1][y] = color;
    }
    if(y-1>=0 && image[x][y-1] == ori_color){
        queue.push(make_pair(x, y-1));
        image[x][y-1] = color;
    }
    if(y+1<image[0].size() && image[x][y+1] == ori_color){
        queue.push(make_pair(x, y+1));
        image[x][y+1] = color;
    }
}
void bfs(vector<vector<int>>& image, int sr, int sc, int color){
    queue<pair<int, int>> q;
    q.push(make_pair(sr,sc));
    int ori_color = image[sr][sc];
    // Edge 1.
    if(image[sr][sc] == color){
        return;
    }else{
        while(!q.empty()){
            pair<int, int> element = q.front();
            q.pop();
            image[element.first][element.second] = color;
            check_4dir(image, element.first, element.second, q, color, ori_color);
        }
    }
}

/*
 * Optimize
 * DFS
 * use recursive call to check each cell.
 */
void dfs(vector<vector<int>>& image, int i, int j,int ori_color, int color)
{
    if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j] == color || image[i][j] != ori_color)
    {
        return;
    }
    image[i][j] = color;
    dfs(image,i-1,j,ori_color,color);
    dfs(image,i+1,j,ori_color,color);
    dfs(image,i,j-1,ori_color,color);
    dfs(image,i,j+1,ori_color,color);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    // BFS
    bfs(image,sr, sc, color);

    // DFS
    dfs(image, sr, sc, image[sr][sc], color)
    return image;
}