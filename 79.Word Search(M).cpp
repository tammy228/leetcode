#include <vector>
#include <queue>
#include <string>
using namespace std;
/*
 * My Solution
 * for each start position use dfs to search if there is match
 * this question is technically backtracking, since you need to unmark the position if it's not the right route
 *
 * Time: worst case O(N*3^L) -> N is the letters of the grid, where L is the len of word that need to be search
 * Space: O(N+L) -> for record used matrix(N), L is for recursion stack
 * Complexity Ref: https://leetcode.com/problems/word-search/solutions/2838651/c-backtracking-with-time-complexity-explanation/
 */
bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& used, int index, pair<int ,int> startPosition)
{
    int x = startPosition.first;
    int y = startPosition.second;
    if (x >= board.size() || y >= board[0].size() || x < 0 || y < 0 || used[x][y] || word[index] != board[x][y])
        return false;

    if(index == word.size() - 1){
        return true;
    }


    used[x][y] = true;
    bool searched =  dfs(board, word, used, index+1, {x+1, y}) ||
                     dfs(board, word, used, index+1, {x, y+1}) ||
                     dfs(board, word, used, index+1, {x-1, y}) ||
                     dfs(board, word, used, index+1, {x, y-1});
    used[x][y] = false;
    return searched;
}
bool exist(vector<vector<char>>& board, string word) {
    char startWord = word[0];

    for (int i=0; i< board.size(); i++)
    {
        for (int j=0; j<board[0].size(); j++)
        {
            if (board[i][j] == startWord)
            {
                int index = 0;
                vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
                bool searched = dfs(board, word, used, index, {i, j});
                if (searched)
                    return true;
            }
        }
    }
    return false;
}