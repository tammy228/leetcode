#include <vector>
using namespace std;

/**
 * My Solution
 * Use array to check if there are repetition
 *
 * Time: O(MN) -> where M = board.size(), N = board[0].size()
 * Space: O(MN * 3) -> O(MN)
 */
int det_three_x_three(int row, int col)
{
    int three_row = row / 3;
    int three_col = col / 3;
    if (three_row == 0 && three_col == 0)
        return 1;
    else if (three_row == 0 && three_col == 1)
        return 2;
    else if (three_row == 0 && three_col == 2)
        return 3;
    else if (three_row == 1 && three_col == 0)
        return 4;
    else if (three_row == 1 && three_col == 1)
        return 5;
    else if (three_row == 1 && three_col == 2)
        return 6;
    else if (three_row == 2 && three_col == 0)
        return 7;
    else if (three_row == 2 && three_col == 1)
        return 8;
    else
        return 9;
}
bool isValidSudoku(vector<vector<char>> &board)
{
    int column[10][10] = {0};
    int row[10][10] = {0};
    int three_x_three[10][10] = {0};
    // row
    for (int i = 0; i < board.size(); i++)
    {
        // column
        for (int j = 0; j < board[0].size(); j++)
        {
            int three_row = det_three_x_three(i, j);
            int value = board[i][j] - '0';
            if (isdigit(board[i][j]))
            {
                if (row[i][value] == 0 && column[value][j] == 0 && three_x_three[three_row][value] == 0)
                {
                    row[i][value]++;
                    column[value][j]++;
                    three_x_three[three_row][value]++;
                }
                else
                    return false;
            }
        }
    }
    return true;
}