#include <vector>
#include <stack>
using namespace std;
/**
 * My Method
 * In order to get the largest rectangle, we need start_idx, end_idx and the height
 * for each height we need to check if adding current height will get bigger rectangle(e.g current hight is bigger than the height in stack.top())
 * if so, we keep the start_idx.
 * if current height is bigger than the rectangle before, we can leave the rectangle before and
 * update start_idx to current index
 * if not, we need to calculate the biggest rectangle that the bigger height can contribute, then remove them from the stack
 *
 * In order to do above algo, we can use stack to keep track of each height and idx.
 *
 * Time:
 * O(N)
 *
 * Space:
 * O(N)
 */
int largestRectangleArea(vector<int> &heights)
{
    int ans = INT_MIN;
    stack<pair<int, int>> st; // {height, idx}
    for (int i = 0; i < heights.size(); i++)
    {
        int start = i;
        while (!st.empty() && heights[i] < st.top().first)
        {
            int height = st.top().first;
            int idx = st.top().second;
            int area = (i - idx) * height;
            if (area > ans)
                ans = area;
            start = idx;
            st.pop();
        }
        st.push({heights[i], start});
    }
    while (!st.empty())
    {
        int height = st.top().first;
        int id = st.top().second;
        int area = ((heights.size() - id) * height);
        if (ans < area)
            ans = area;
        st.pop();
    }
    return ans;
}