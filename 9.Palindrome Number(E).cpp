#include <string>
using namespace std;

/*
 * My Solution
 * 1. negative numbers are definitely not palindrome
 * 2. if it's positive number(include 0)
 *    then, turn it to string and compare
 *
 * Time: O(N)
 * Space: O(N)
 */
//bool isPalindrome(int x) {
//    if(x < 0) return false;
//    bool ans = true;
//    string x_str = to_string(x);
//    int left = 0, right = x_str.size()-1;
//    while(left <= right)
//    {
//        if(x_str[left++] != x_str[right--])
//        {
//            ans = false;
//            break;
//        }
//    }
//    return ans;
//}

/*
 * Optimize
 * reverse the number and compare in int type
 * reduce the time of convert the number to string
 *
 * Time: O(N)
 * Space: O(1)
 */
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    long long reversed = 0;
    long long temp = x;

    while (temp != 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }

    return (reversed == x);
}