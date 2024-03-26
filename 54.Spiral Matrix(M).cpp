#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
 * My Solution
 * create a four direction array
 * check the answer.size() after each direction iteration
 *
 *  Time: O(MN) -> M is matrix.size() while N is matrix[0].size()
 *  Space: O(1)
 */
pair<int, int> consumeLetters(vector<int>& ans, vector<vector<int>>& matrix, string direction, pair<int, int> startPosition)
{
    int x = startPosition.first;
    int y = startPosition.second;
    if (direction == "right")
    {
        while (y + 1 < matrix[0].size() && matrix[x][y + 1] != 101)
        {
            ans.push_back(matrix[x][++y]);
            matrix[x][y] = 101;
        }
    }
    else if (direction == "down")
    {
        while(x + 1 < matrix.size() && matrix[x + 1][y] != 101)
        {
            ans.push_back(matrix[++x][y]);
            matrix[x][y] = 101;
        }
    }
    else if (direction == "left")
    {
        while(y - 1 >= 0 && matrix[x][y - 1] != 101)
        {
            ans.push_back(matrix[x][--y]);
            matrix[x][y] = 101;
        }
    }
    else
    {
        while(x - 1 < matrix.size() && matrix[x - 1][y] != 101)
        {
            ans.push_back(matrix[--x][y]);
            matrix[x][y] = 101;
        }
    }
    return {x, y};
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    ans.push_back(matrix[0][0]);
    matrix[0][0] = 101;
    pair<int, int> startPosition = {0, 0};
    int total_count = matrix.size() * matrix[0].size();
    vector<string> direction = {"right", "down", "left", "up"};
    while(ans.size() < total_count)
    {
        for(int i=0; i<4; i++)
            startPosition = consumeLetters(ans, matrix, direction[i], startPosition);
    }
    return ans;
}
