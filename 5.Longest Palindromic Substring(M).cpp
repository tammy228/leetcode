#include <string>
using namespace std;
/*
 * My Solution
 * Use two pointer to do, the main idea is simultaneously expand both pointer, and compare if they are same
 * There are two cases, odd and even
 * odd: left and right pointer start with 0
 * even: left and right pointer start with 0, 1
 *
 * Edge Case:
 * If there is no palindrome longer than 1
 *
 * Time:O(2N)? -> O(N)
 * Space: O(1)
 */
string longestPalindrome(string s) {
    int left, right;
    int maxLeft = 0, maxRight = 0;
    // odd
    for(int i=0; i<s.size(); i++)
    {
        left = i;
        right = i;
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            if(right - left > maxRight - maxLeft)
            {
                maxRight = right;
                maxLeft = left;
            }
            right++;
            left--;
        }
    }
    left = 0, right = 1;
    // even
    for(int i=0; i<s.size() - 1; i++)
    {
        left = i;
        right = i + 1;
        while(left >= 0 && right < s.size() && s[left] == s[right] )
        {
            if(right - left > maxRight - maxLeft)
            {
                maxRight = right;
                maxLeft = left;
            }
            right++;
            left--;
        }
    }
    return s.substr(maxLeft, (maxRight-maxLeft+1));
}