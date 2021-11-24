#include<vector>
#include<iostream>
using namespace std;
/*
 * My Solution
 * *(Sliding window)
 * 1. iterate vector if right<left -> left = right
 * 2. during iteration
 *    if element < left: left  = right = element
 *    else calculate profit
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
