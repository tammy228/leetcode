#include <stdint.h>
#include <bitset>
#include <string>
#include <math.h>
using namespace std;

/*
 * My Solution
 * Use bitset to store the value, and cast to string then calculate the value of reverse order of the string
 *
 * Time: O(32) -> O(1)
 * Space: O(32) -> O(1)
 */
//uint32_t reverseBits(uint32_t n) {
//    bitset<32> bits(n);
//    string str = bits.to_string();
//    int idx = 0;
//    uint32_t  ans = 0;
//
//    for(char ch : str)
//    {
//        if (ch == '1')
//            ans += pow(2, idx);
//        idx++;
//    }
//    return ans;
//}

/*
 * Optimize
 *
 */
uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
        ans <<= 1;
        ans |= (n & 1);
        n >>= 1;
    }
    return ans;
}