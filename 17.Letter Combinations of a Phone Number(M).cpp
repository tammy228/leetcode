#include <string>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;
/*
 * My Solution
 * First, use map to store number-letters correspondence
 * while iterate digits
 * for each digit
 *      iterate the combinations store in ans(vector<string>)
 *
 * While implementing, I dry run the code and found out I need push_front() and pop_back()
 * so I use list for temp storage
 *
 * Time: O(N^3)
 * Space: O(N) -> extra space for list
 */
//vector<string> letterCombinations(string digits) {
//    unordered_map<char, string> map;
//    vector<string> ans;
//    list<string> list_ans;
//    if (digits.size() == 0) return ans;
//    list_ans.push_back("");
//    map['2'] = "abc";
//    map['3'] = "def";
//    map['4'] = "ghi";
//    map['5'] = "jkl";
//    map['6'] = "mno";
//    map['7'] = "pqrs";
//    map['8'] = "tuv";
//    map['9'] = "wxyz";
//    for (int i=0; i<digits.size(); i++)
//    {
//        int ans_size = list_ans.size();
//        for (int j=0; j<ans_size; j++)
//        {
//            string letters = map[digits[i]];
//            string comb = list_ans.back();
//            list_ans.pop_back();
//            for (int k=0; k<letters.size(); k++)
//            {
//                list_ans.push_front(comb+letters[k]);
//            }
//        }
//    }
//    copy(begin(list_ans), end(list_ans), back_inserter(ans));
//    return ans;
//}

/*
 * Optimize
 * using backtracking
 *
 * Time: O(N*4^N) -> N is digits.size()
 * Space: O(N)    -> N is for recursive call
 */
void backtracking(int index, string& digits, unordered_map<char, string>& map, string& result, vector<string>& ans) {
    if(result.size() == digits.size()) {
        ans.push_back(result);
        return;
    }

    for (int i=0; i<map[digits[index]].size(); i++)
    {
        result += map[digits[index]][i];
        backtracking(index+1, digits, map, result, ans);
        result = result.substr(0, result.size() - 1);
    }
    return;
}
vector<string> letterCombinations(string digits) {
    unordered_map<char, string> map;
    string result;
    vector<string> ans;
    if (digits.size() == 0) return ans;
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";
    backtracking(0, digits, map, result, ans);
    return ans;
}