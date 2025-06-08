#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * My Method
 * Compare all len(s1) of substring in s2
 *
 * Time:
 * (N*MlogM) , where N = s2.size(), M = s1.size()
 * Space:
 * O(1)
 */
// bool isContainPermu(string s1, string sub_s2)
// {
//     sort(s1.begin(), s1.end());
//     sort(sub_s2.begin(), sub_s2.end());
//     return true ? s1 == sub_s2 : false;
// }
// bool checkInclusion(string s1, string s2)
// {
//     if (s2.size() < s1.size())
//         return false;
//     int left = 0;
//     while (left <= s2.size() - s1.size())
//     {
//         if (!isContainPermu(s1, s2.substr(left, s1.size())))
//         {
//             left++;
//         }
//         else
//         {
//             return true;
//         }
//     }
//     return false;
// }
/**
 * Optimized
 *
 * Since input only contain lowletter, therefore we can use 26 table to track
 * current window(substring of s2) and s1 to see if they are match.
 * However, we don't need to match two tables everytime, every each time we move the window
 * only add one character and remove one charcter, so we only need to compare two table for the first time
 *
 * Time: O(N)
 *
 * Space: O(26*2) == O(1)
 *
 */
bool checkInclusion(string s1, string s2)
{
    if (s2.size() < s1.size())
        return false;
    int s1_table[26] = {0};
    int s2_table[26] = {0};
    int matches = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        s1_table[s1[i] - 'a']++;
        s2_table[s2[i] - 'a']++;
    }

    for (int j = 0; j < 26; j++)
        if (s1_table[j] == s2_table[j])
            matches++;

    for (int i = 1; i <= s2.size() - s1.size(); i++)
    {
        if (matches == 26)
        {
            return true;
        }
        else
        {
            s2_table[s2[i - 1] - 'a']--;
            if (s1_table[s2[i - 1] - 'a'] == s2_table[s2[i - 1] - 'a'])
                matches++;
            else if (s2_table[s2[i - 1] - 'a'] + 1 == s1_table[s2[i - 1] - 'a'])
                matches--;

            s2_table[s2[i + s1.size() - 1] - 'a']++;
            if (s1_table[s2[i + s1.size() - 1] - 'a'] == s2_table[s2[i + s1.size() - 1] - 'a'])
                matches++;
            else if (s2_table[s2[i + s1.size() - 1] - 'a'] - 1 == s1_table[s2[i + s1.size() - 1] - 'a'])
                matches--;
        }
    }
    return matches == 26;
}