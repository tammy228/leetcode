#include <unordered_map>
#include <string>
using namespace std;
/*
 * My Solution
 * Use map to store all roman numeral rules
 * For most of the case it's descending, therefore just add them together.
 * However, if we encounter ascending part, we need to do subtraction.
 *
 * Time:
 * O(M) -> M for s.size()
 *
 * Space:
 * O(1) -> store roman numeral rules
 */
int romanToInt(string s) {
    unordered_map<char, int>map;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
    int check = INT_MAX;
    int ans = 0;
    for(char ch : s){
        if(map[ch] <= check){
            ans += map[ch];
            check = map[ch];
        }else{
            ans -= check;
            ans += (map[ch] - check);
        }
    }
    return ans;
}