#include<iostream>
#include<vector>
#include <queue>
#include <unordered_set>
using namespace std;
/*
 * My Solution
 * *(DP)
 * 1. Similar to brute force, check every coins combinations, but use dp[] to store
 * 2. iterate 0 -> amount, store the minimum coin number of that element
 *
 * Time: O(amount * coin.size())
 * Space: O(amount)
 * **(Greedy doesn't work)
 * Ex: [1,3,4,5] amount=7
 *
 * Edge Case:
 * 1. can't not find any combinations to make up to amount
 *
 * Attention:
 * Can not init dp array with INT_MAX, it will error with if condition
 */
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0; // amount 0 requires 0 coins to achieve.

    for(int i=1; i<=amount; i++){
        for(int j=0; j<coins.size(); j++){
            if(i - coins[j] >= 0)
                dp[i] = min(dp[i], 1 + dp[amount - coins[j]]);
        }
    }
    if(dp[amount] == amount+1)
        return -1;
    else
        return dp[amount];
}

/*
 * BFS Version
 * Solve it as a Tree
 *
 * Time:
 */
//int bfs(vector<int>& coins, int amount){
//    queue<pair<long, int>> q;
//    q.push({0,0}); // q.first: current_amount, q.second: level
//    unordered_set<int> seen;
//    while(!q.empty() && q.front().first <= amount){
//        long current_amount = q.front().first;
//        int level = q.front().second;
//        q.pop();
//        if(current_amount == amount)
//            return level; // 因為是BFS，第一個找到的一定是最小的
//        if(seen.count(current_amount))
//            continue;
//        for(auto coin: coins) {
//            if(current_amount + coin <= amount)
//                q.push({current_amount + coin, level + 1});
//        }
//        seen.insert(current_amount);
//    }
//    return -1;
//}
//int coinChange(vector<int>& coins, int amount) {
//    return bfs(coins, amount);
//}
