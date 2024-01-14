#include <vector>
#include <string>
using namespace std;

/*
 * Optimize
 * my thought is to find all substring and check if it is palindromic, but it's going to be O(N^3)
 * the tricky part is in finding substring, we don't need to find every substring
 * because if the substring is not palindromic, the string that contain the substring will not be palindromic too
 *
 * So the optimize version will be iterating each character and use two pointer to simultaneously expand both direction
 * Notice that, if iterating character, the substring will all be odd, so we need to add even version by iterating
 * two characters together
 *
 * 1. iterate one character(odd)
 *    a. two pointer start position is in character position
 *    b. expand in two direction with in >=0 && < len(string)
 *    c. compare two pointer position of character are the same or not
 * 2. iterate two characters(even)
 *
 * Edge Case:
 * 1. s.size() == 1
 *
 * Time: O(N)
 *
 * Space: O(1)
 */
int countSubstrings(string s) {
    int ans = 0;
    // odd
    for(int i=0; i<s.size(); i++)
    {
        int left=i, right=i;
        while(left >= 0 && right < s.size())
        {
            if(s[left] != s[right])
                break;
            left--;
            right++;
            ans++;
        }
    }
    if (s.size() == 1) return ans;

    // even
    for(int i=0; i<s.size()-1; i++)
    {
        int left=i, right=i+1;
        while(left >= 0 && right < s.size())
        {
            if(s[left] != s[right])
                break;
            left--;
            right++;
            ans++;
        }
    }
    return ans;
}