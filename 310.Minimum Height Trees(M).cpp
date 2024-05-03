#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
/**
 * My Solution
 * In example, we can find out that leaves (which edge is 1) will affect the height
 * if we add node to the leaf it will increase the height
 * In other words, if we count height from the leaves, it's a easy way to find the root
 * And also, if there is only two nodes, it won't matter which node to be root
 *
 *
 * 1. Find the leaves(which edge is 1)
 *  1a. create adj list for vetices
 *  1b. if adj list has only one vertex, it is leaf
 *  1c. gather the leaves
 * 2. delete the leaves
 *  2a. iterate the adj list for each leaf
 *  2b. update edge count
 * 3. repeat 1. 2., until the number of nodes are 1 or 2
 * 4. return the value
 *
 * Edge Case:
 * 1. only has one element
 *
 * Time:
 * O(E+V)
 *
 * Space:
 * O(E+V)
 */
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1)
        return {0};

    vector<vector<int>> adj_list(n);
    vector<int> edge_count(n, 0);
    vector<int> ans;

    // init adjacency list and edge count
    // O(E)
    for (auto &edge : edges)
    {
        int a_node = edge[0];
        int b_node = edge[1];
        adj_list[a_node].push_back(b_node);
        adj_list[b_node].push_back(a_node);
        edge_count[a_node]++;
        edge_count[b_node]++;
    }

    // 1c.
    // O(n)
    queue<int> leaves;
    for (int i = 0; i < n; i++)
        if (edge_count[i] == 1)
            leaves.push(i);

    // 3.
    // O(E + V)
    while (n > 2 && !leaves.empty())
    {
        int level = leaves.size();
        while (level--)
        {
            // 2.
            int node = leaves.front();
            leaves.pop();
            n--;
            for (int i = 0; i < adj_list[node].size(); i++)
            {
                if (--edge_count[adj_list[node][i]] == 1)
                    leaves.push(adj_list[node][i]);
            }
        }
    }
    while (!leaves.empty())
    {
        ans.push_back(leaves.front());
        leaves.pop();
    }
    return ans;
}
