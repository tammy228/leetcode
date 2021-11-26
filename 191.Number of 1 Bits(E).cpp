#include<iostream>
using namespace std;
/*
 * My Solution
 * *(Bit Manipulation)
 * 1. use "<<" to isolate one bit and use "&" to check if that bit is 1 or not
 *
 * Time: O(n.size()) -> O(1)
 *
 */
int hammingWeight(uint32_t n) {
    int ans=0;
    while(n > 0){
        if(n & 1)
            ans++;
        n = n >> 1;
    }
    return ans;
}
/*
 * Optimize
 * 1. n = n & (n-1) : n-1 相當於">>" , & 相當於 直接處理下一個 1 忽略中間所有的0
 * 2. ans++;
 * Ex: n = 100000
 *  100000
 * &011111
 * -------
 *  000000
 */
