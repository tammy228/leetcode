#include <algorithm>
using namespace std;
/*
 * My Solution
 * 1. iterate both string from the smallest digits
 * 2. every each iteration count 1's in(carry, s[i], t[i])
 *    if even: result digit -> 0
 *    if odd: result digit -> 1
 *    both scenario need to check carry
 *
 * Time:
 * O(N): N for max(a.size(), b.size())
 *
 * Space:
 * O(1)
 */
string addBinary(string a, string b) {
    int maxLen = max(a.size(), b.size());
    char carry = '0';
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string result = "";
    for(int i=0; i<maxLen; i++){
        char c_a = i < a.size() ? a[i] : '0';
        char c_b = i < b.size() ? b[i] : '0';
        int ones = carry-'0' + c_a-'0' + c_b-'0';
        // zero || two
        if(ones % 2 == 0 && ones > 0){
            result = '0' + result;
            carry = '1';
        }else if(ones % 2 == 0){
            result = '0' + result;
            carry = '0';
        // one || three
        }else if(ones % 2 == 1 && ones > 1){
            result = '1' + result;
            carry = '1';
        }else {
            result = '1' + result;
            carry = '0';
        }
    }
    if(carry == '1')
        return '1'+result;
    else
        return result;

}

/*
 * Optimize
 * without reversing input string
 *
 * Time:
 * O(N): max(a.size(), b.size())
 *
 * Space:
 * O(1)
 */

string addBinary(string a, string b)
{
    string s = "";

    int c = 0, i = a.size() - 1, j = b.size() - 1;
    while(i >= 0 || j >= 0 || c == 1)
    {
        c += i >= 0 ? a[i --] - '0' : 0;
        c += j >= 0 ? b[j --] - '0' : 0;
        s = char(c % 2 + '0') + s;
        c /= 2;
    }

    return s;
}