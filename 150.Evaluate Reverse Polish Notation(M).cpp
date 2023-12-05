#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * My Solution
 * Use stack to store numbers, when encounter operators pop up two numbers
 *
 * Fail Case:
 * 1. If push number in first "+" will fail, because there is no number after sign
 * 2. After calculation the result will overflow, need use long long int to store
 *
 * Time:
 * O(N): where N is tokens.size()
 *
 * Space:
 * O(N): stack, N is tokens.size()
 */
//int evalRPN(vector<string>& tokens) {
//    stack<long long int> numbers;
//    for(int i=0; i<tokens.size(); i++){
//        int operators = int(tokens[i][0]);
//        // if(i == "+" || i == "-" || i == "*" || i == "/")  可以直接用string 等於
//        if(tokens[i].size() == 1 && (operators == 42 || operators == 43 || operators == 45 || operators == 47)){
//            long long int num1 = numbers.top();
//            numbers.pop();
//            long long int num2 = numbers.top();
//            numbers.pop();
//            long long int calc;
//            // *
//            if(operators == 42){
//                calc = num1 * num2;
//                // +
//            }else if(operators == 43){
//                calc = num1 + num2;
//                // -
//            }else if(operators == 45){
//                calc = num2 - num1;
//                // /
//            }else{
//                calc = num2 / num1;
//            }
//            numbers.push(calc);
//        }else{
//            numbers.push(stoll(tokens[i]));
//        }
//    }
//    return numbers.top();
//}

/*
 * Optimize Solution
 * Using map and lambda function
 *
 * Time:
 * O(N): where N is tokens.size()
 *
 * Space:
 * O(N+4): stack, N is tokens.size(), 4 is for map size
 */
int evalRPN(vector<string>& tokens) {
    unordered_map<string, function<int (long long int, long long int) > > map = {
            { "+" , [] (long long int a, long long int b) { return a + b; } },
            { "-" , [] (long long int a, long long int b) { return a - b; } },
            { "*" , [] (long long int a, long long int b) { return a * b; } },
            { "/" , [] (long long int a, long long int b) { return a / b; } }
    };
    std::stack<long long int> stack;
    for (string& s : tokens) {
        if (!map.count(s)) {
            stack.push(stoll(s));
        } else {
            long long int op1 = stack.top();
            stack.pop();
            long long int op2 = stack.top();
            stack.pop();
            stack.push(map[s](op2, op1));
        }
    }
    return stack.top();
}