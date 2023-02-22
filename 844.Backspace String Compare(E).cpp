#include <string>
#include <stack>
using namespace std;

/*
 * My Solution
 * Use two stack to store processed input
 * and then compare two stack to see if they are same
 *
 * Time:
 * O(M + N) -> N for max(s.size(), t.size())
 *
 * Space:
 * O(M + N) -> N for s.size() M for t.size()
 */
bool isSameStack(stack<char> stack1, stack<char> stack2)
{
    // Create a flag variable
    bool flag = true;
    // Check if size of both stacks are same
    if (stack1.size() != stack2.size()) {
        flag = false;
        return flag;
    }

    // Until the stacks are not empty
    // compare top of both stacks
    while (stack1.empty() == false) {
        // If the top elements of both stacks
        // are same
        if (stack1.top() == stack2.top()) {
            // Pop top of both stacks
            stack1.pop();
            stack2.pop();
        }
        else {
            // Otherwise, set flag to false
            flag = false;
            break;
        }
    }

    // Return flag
    return flag;
}
bool backspaceCompare(string s, string t) {
    stack<char> chs;
    stack<char> cht;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '#' && !chs.empty()){
            chs.pop();
        }
        if(s[i] != '#'){
            chs.push(s[i]);
        }
    }

    for(int i=0; i<t.size(); i++){
        if(t[i] == '#' && !cht.empty()){
            cht.pop();
        }
        if(t[i] != '#'){
            cht.push(t[i]);
        }
    }

    return isSameStack(chs, cht);
}
