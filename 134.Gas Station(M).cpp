#include <vector>
#include <queue>
using namespace std;

/**
 * My Solution(Time Limit)
 * First list out all possible start position, where the condition is gas[i] >= cost[i]
 * Then, walk through all possible start position to see if there is a solution
 *
 *
 * Time: O(N^2)
 * Space: O(N)
 *
 */
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    queue<int> possible_start;
    for (int i = 0; i < gas.size(); i++)
    {
        if (cost[i] <= gas[i])
            possible_start.push(i);
    }
    while (!possible_start.empty())
    {
        int start_pos = possible_start.front();
        possible_start.pop();
        int tank = gas[start_pos];
        int iteration = gas.size();
        bool existed = true;
        while (iteration--)
        {
            if (tank - cost[start_pos] < 0)
            {
                existed = false;
                break;
            }
            else
            {
                if (start_pos == gas.size() - 1)
                {
                    tank = tank - cost[start_pos] + gas[0];
                    start_pos = -1;
                }
                else
                    tank = tank - cost[start_pos] + gas[start_pos + 1];
            }
            start_pos++;
        }
        if (existed)
            return start_pos;
    }
    return -1;
}

/**
 * Optimize
 * We know there is only one solution, if `total_gas < total_cost` return -1
 * then we start at any index, if `curr_gas < 0` means that there is no solution between these stations
 * proof:
 *     we know curr_gas must > 0
 *     if curr_gas + gas[i] - cost[i] < 0
 *     then gas[i] - cost[i] is also < 0
 *     therefore we know there is no valid starting point between these gas station
 * Time: O(N)
 * Space: O(1)
 */
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int total_gas = 0, total_cost = 0, curr_gas = 0, starting_point = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        total_gas += gas[i];
        total_cost += cost[i];
        curr_gas += gas[i] - cost[i];
        if (curr_gas < 0)
        {
            starting_point = i + 1;
            curr_gas = 0;
        }
    }
    return (total_gas < total_cost) ? -1 : starting_point;
}