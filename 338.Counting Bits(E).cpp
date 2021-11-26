#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * 1. iterate every number
 * 2. count every bit of each number
 *
 * Time: O(n*logn)
 *
 */
int countbit(int num){
    int bit=0;
    while(num){
        if(num&1)
            bit++;
        num = num >> 1;
    }
    return bit;
}
vector<int> countBits(int n) {
    vector<int> ans;
    for(int i=0; i<=n; i++)
        ans.push_back(countbit(i));
    return ans;
}
/*
 * Optimize
 * *(DP)
 * 1. init dp[0] = 0
 * 2. if number is power of 2, then number of  1 bit will be 1
 *    else ans = 1 + dp[n-significant]
 * EX:
 * 0: 0000 -> 0
 * 1: 0001 -> 1 + dp[n-1]
 * 2: 0010 -> 1 + dp[n-2]
 * 3: 0011 -> 1 + dp[n-2]
 * 4: 0100 -> 1 + dp[n-4]
 * 5: 0101 -> 1 + dp[n-4]
 * 6: 0110 -> 1 + dp[n-4]
 * 7: 0111 -> 1 + dp[n-4]
 * 8: 1000 -> 1 + dp[n-8]
 *
 * Time: O(n)
 */
int CountBits(int n){
    vector<int> dp(n+1, 0);
    if(n == 0) return {0};
    vector<int> ans;
    ans[0] = 0;
    int offset = 0;
    for(int i=1; i<=n; i++){
        if(offset * 2 == i)
            offset = i;
        dp[i] = 1 + dp[i-offset];
    }
    return dp[n+1];
}