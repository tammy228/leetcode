#include<iostream>
#include<vector>
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
    if(dp[amount] == INT_MAX)
        return -1;
    else
        return dp[amount];
}

