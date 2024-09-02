#include <string>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    int longer_length = word1.size() > word2.size() ? word1.size() : word2.size();
    string ans = "";
    for (int i = 0; i < longer_length; i++)
    {
        if (word1.size() > i)
            ans += word1[i];
        if (word2.size() > i)
            ans += word2[i];
    }
    return ans;
}