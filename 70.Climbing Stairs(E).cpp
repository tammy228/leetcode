#include <vector>
using namspace std;
/*
 * My Solution
 * Use DP to solve, Dp initial 1 step, and 2 step
 *
 * Time:
 * O(n)
 *
 * Space:
 * O(n)
 */
int climbStairs(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

/*
 * Optimize
 * We can use two variables to do store information
 */

int climbStairs(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    int first = 1;
    int second = 2;
    int result;
    for(int i=3; i<=n; i++){
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

