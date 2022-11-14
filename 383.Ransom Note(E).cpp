#include<unordered_map>
using namespace std;

/*
 * My Solution
 * basically find out if “ransomNote” is common sequence of “magazine”
 * 1. use map to store “magazine” chars
 * 2. check “ransomNote”
 *
 * Edge Case:
 * 1. if ransomNote is null -> return true
 * 2. if magazine is null and ransomNote is not null -> return false
 *
 * Time:
 * O(m): where m is the number of the bigger size between ransomNote and magazine
 * Space:
 * O(s): where s is the size of magazine
 */
bool canConstruct(string ransomNote, string magazine) {
    if(ransomNote.size() == 0) return true;
    if(magazine.size() == 0 && ransomNote.size() != 0) return false;
    unordered_map<char, int> map;
    for(char s : magazine)
        map[s]++;
    for(char s : ransomNote){
        if(map.count(s) == 0 || map[s] == 0)
            return false;
        map[s]--;
    }
    return true;
}