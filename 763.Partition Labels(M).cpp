#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
/*
 * My Solution
 * 1. store the last index of every distinct character(hashtable)(***Be careful of index and size ***)
 * 2. iterate the string to find the partition
 *    size: partition label
 *    end: char's last index
 *
 * Time : O(n)
 * Edge Case
 * 1. upper/lower case(V)
 * 2. one character: return 1
 * 3. all of the characters are same: return string size
 */
vector<int> partitionLabels(string s) {
    unordered_map<char, int> map;
    // Edge 2.
    if(s.size() == 1) return {1};
    // 1.
    for(int i=0; i<s.size(); i++)
        map[s[i]] = i+1;
    // Edge 3.
    if(map.size() == 1) return {map.begin()->second};
    int endIndex=0, size=0, lastSize=0;
    vector<int> ans;
    // 2.
    for(int i=0; i<s.size(); i++){
        if(map[s[i]] > endIndex)
            endIndex = map[s[i]];
        size++;
        if((size + lastSize ) == endIndex){
            ans.push_back(size);
            lastSize += size;
            size = 0;
        }
    }
    return ans;
}
//int main(){
//    string s = "ababcbacadefegdehijhklij";
//    vector<int> ans = partitionLabels(s);
//    for(auto & i : ans)
//        cout << i << endl;
//}
