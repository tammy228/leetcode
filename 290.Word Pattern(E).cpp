#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool wordPattern(string pattern, string s) {
    unordered_map<char, string> map;
    vector<string> str_list;
    string tmp;
    stringstream ss(s);
    while(getline(ss, tmp, ' ')){
        str_list.insert(str_list.end(), tmp);
    }
    if(pattern.size() != str_list.size()) return false;
    for(int i=0; i<pattern.size(); i++){
        if(map.count(pattern[i]) == 0) {
            tmp = str_list[i];
            auto it = find_if(map.begin(), map.end(), [& tmp](auto &&pair) {return pair.second == tmp; });
            if(it == end(map))
                map[pattern[i]] = str_list[i];
            else
                return false;
        }
        else
            if(map[pattern[i]] != str_list[i])
                return false;
    }
    return true;
}
//int main(){
//    string pattern = "abba";
//    string s = "dog dog dog dog";
//    bool ans = wordPattern(pattern, s);
//    cout << ans;
//}
