#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
/**
 * My Method
 * I have absolutely no idea how to solve this....
 * Optimize
 * First, we consider (position, time) as x-y plot, in order to become a car fleet
 * there must be intersect before they reach the target position.
 *
 * And, if we sort position, and iterate the position with reverse order, we can calculate
 * how much time we need to travel to target position.
 * And if the travel time of position[i-1] < position[i] travel time, it means they are
 * going to meet before the target, so they are going to be a fleet.
 * And since, if they become a fleet they are traveling with minimum speed, that means
 * we just need to keep position[i]'s speed.
 *
 * As for data structure, we can use stack to do above algorithm, for each position we pop
 * the top of stack and check the time of reach target position,
 * if current_time[i] < stack_top_time -> become fleet, ignore current and keep the top
 * else current_time[i] > stack_top_time -> new fleet, push into stack
 *
 * Time: O(N)
 * Space: O(N)
 */
bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first; // descending order
}

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<pair<int, int>> pos_sp; // <position, speed>
    stack<float> st;               // time
    for (int i = 0; i < position.size(); i++)
    {
        pos_sp.push_back({position[i], speed[i]});
    }
    sort(pos_sp.begin(), pos_sp.end(), compare);

    for (const pair<int, int> &it : pos_sp)
    {
        if (!st.empty())
        {
            float current_time = (target - it.first) / static_cast<float>(it.second);
            if (current_time <= st.top())
                continue;
        }
        st.push((target - it.first) / static_cast<float>(it.second));
    }
    return st.size();
}