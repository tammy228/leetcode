#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
/*
 * My Solution
 * *(直式乘法)
 * 1. iterate both number to multiply (be careful of "carry" and bit manipulation) store as string
 * 2. add all string up
 *
 * Time: O(mn)
 *       m: num1.size()
 *       n: num2.size()
 * Edge Case
 * 1. One number is zero
 * 2. Both number are zero
 *
 */
//string multiply(string num1, string num2) {
//    if(num1 == "0" || num2  == "0")
//        return "0";
//    vector<string> mul;
//    for(int i=num1.size()-1; i>=0; i--){
//        int carry = 0;
//        string tmp = "";
//        for(int j=num2.size()-1; j>=0; j--){
//            int res = (num2[j] - '0') * (num1[i] - '0');
//            tmp = to_string((res + carry) % 10) + tmp;
//            carry = res / 10;
//        }
//        if(carry)
//            tmp = to_string(carry) + tmp;
//        for(int k=num1.size()-1; k>i; k--)
//            tmp += '0';
//        mul.push_back(tmp);
//    }
//    for(auto & it: mul)
//        cout << it << endl;
//    reverse(mul[0].begin(), mul[0].end());
//    string ans = mul[0];
//    for(int i=1; i<mul.size(); i++) {
//        int len = mul[i].size() > ans.size() ? mul[i].size() : ans.size();
//        reverse(mul[i].begin(), mul[i].end());
//        int carry = 0, ans_digit=0, mul_digit=0;
//        string tmp = "";
//        for (int k=0; k<len; k++) {
//            if(k > ans.size()-1)
//                ans_digit = 0;
//            else
//                ans_digit = ans[k] - '0';
//            if(k > mul[i].size()-1)
//                mul_digit = 0;
//            else
//                mul_digit = mul[i][k] - '0';
//            int res = ans_digit + mul_digit;
//            tmp += to_string((res  + carry) % 10);
//            carry = res / 10;
//        }
//        if(carry)
//            tmp += '1';
//        ans = tmp;
//    }
//    reverse(ans.begin(), ans.end());
//    return ans;
//}
/*
 * Optimize
 * 1. add all the product while multiply them
 */
string multiply(string num1, string num2){
    if(num1 == "0" || num2  == "0")
        return "0";
    string s;
    vector<int> ans(num1.size()+num2.size(), 0);
    for(int i=num1.size()-1; i>=0; i--){
        for(int j=num2.size()-1; j>=0; j--){
            int res = (num2[j] - '0') * (num1[i] - '0');
            ans[i+j] += (res + ans[i+j+1]) / 10;
            ans[i+j+1] = (res + ans[i+j+1]) % 10;
        }
    }
    for(auto & it : ans)
        if(s.size() != 0 || it != 0)
            s += to_string(it);
    return s;
}
int main(){
    string num1 = "456";
    string num2 = "123";
    string ans = multiply(num1, num2);
    cout << "ans: " << ans << endl;
}