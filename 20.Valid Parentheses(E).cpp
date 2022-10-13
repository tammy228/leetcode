#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
/*
 *  My Solution
 *  map <str, str> //first: ")", "}", "]" , second : "(", "{", "["
 *  Ex: <")", "(">
 *
 *  vector<str> stack;
 *  1. iterate the string, while iterating check if the character is right or left Parentheses(map.find())
 *	   if "left side": push in to stack;
 *	   if "right side":
 *	   if stack.top() is corresponding "left side" of the character:
 *			 pop up from stack;
 *     not return false;
 *
 *  2. if stack.empty(): return true;
 *	   not return false;
 *
 *  Edge Case: s.size() == 1 return false
 *
 *  Missing Part: didn't consider the case, that if stack is empty therefore there is no stack.back()
 *
 *  Time: O(n)
 *  Space: O(n)
 */
bool isValid(string s) {
    if(s.size() == 1) return false;
    unordered_map<char, char> map;
    map[')'] = '(';
    map['}'] = '{';
    map[']'] = '[';
    vector<char> stack;
    for(char & i : s){
        if(map.count(i) == 0)
            stack.push_back(i);
        else{
            if(!stack.empty() && stack.back() == map[i])
                stack.pop_back();
            else
                return false;
        }
    }
    if(stack.empty())
        return true;
    else
        return false;
}
