#include <string>
using namespace std;

/**
 * Optimize
 * Brute force way will be check every substring and check if the substring is valid,
 * the substring is valid only if len(substring) - maxFrequentNum <= k.
 * Therefore, if we want to optimize the method, we can use sliding window to find valid substring
 * Once the condition does not meet shift the left pointer until the substring is valid
 *
 * Time: O(N)
 *
 * Space: O(26)
 */
int characterReplacement(string s, int k)
{
    int table[26] = {0};
    int left = 0, right = 0;
    int ans = 0;
    int max_freq_num = 1;
    while (right < s.size())
    {
        table[s[right] - 'A']++;
        max_freq_num = max(max_freq_num, table[s[right] - 'A']);
        if ((right - left + 1) - max_freq_num <= k)
        {
            ans = max(ans, (right - left + 1));
            right++;
        }
        else
        {
            while ((right - left + 1) - max_freq_num > k)
            {
                table[s[left] - 'A']--;
                left++;
            }
            right++;
        }
    }
    return ans;
}