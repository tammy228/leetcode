#include<vector>
#include<iostream>
using namespace std;
/*
 * My Solution
 * *(Sliding window)
 *
 * use two pointers left and right, left: buy, right: sell
 * during the iteration,
 *  if right value > left value:
 *      left = right (and we don't need to calc the profit)
 *  else
 *      calc the profit, and if it's bigger than previous replace it.
 *
 *
 * Time: O(n)
 *
 * Edge Case:
 * 1. One day: return 0
 */
int maxProfit(vector<int>& prices) {
    if(prices.size() == 1)
        return 0;
    int left=0, ans=0;
    for(int right=1; right<prices.size(); right++){
        if(prices[right] >= prices[left])
            ans = max(ans, prices[right] - prices[left]);
        else
            left = right;
    }
    return ans;
}