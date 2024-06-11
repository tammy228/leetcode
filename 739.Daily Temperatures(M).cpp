#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * My Solution(TL)
 * with each temperature, search all array to find if there is warmer temperature
 *
 * Time: O(N^2)
 *
 */
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> ans;

    for (int i = 0; i < temperatures.size() - 1; i++)
    {
        int index = i;
        while (index < temperatures.size() && temperatures[index++] <= temperatures[i])
            ;
        if (index - 1 < temperatures.size() && temperatures[index - 1] > temperatures[i])
            ans.push_back(index - 1 - i);
        else
            ans.push_back(0);
    }
    ans.push_back(0);
    return ans;
}

/**
 * Optimize
 * Use stack to keep track of temperature, stack is used for pushing index
 * each iteration, we take out the top of the stack and compare to current temp.
 * if curr_temp > top_temp:  pop the top until the top is greater current and push current index into the stack
 * else: update the ans, push current index into the stack
 *
 * Time: O(N) -> the inner while loop only visit once, worst case should be O(2N)
 * Space: O(N) -> stack usage
 */
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st;
    vector<int> ans;
    ans.push_back(0);
    st.push(temperatures.size() - 1);
    for (int i = temperatures.size() - 2; i >= 0; i--)
    {
        int curr_temp = temperatures[i];
        while (!st.empty() && curr_temp >= temperatures[st.top()])
            st.pop();

        // if there is no greater temperature, push 0 into ans
        if (st.size())
            ans.push_back(st.top() - i);
        else
            ans.push_back(0);
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
