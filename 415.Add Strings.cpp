#include <iostream>
using namespace std;
string addStrings(string&  num1, string& num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string ans = "";
    int carry = 0;
    if(num1.size() > num2.size()) {
        swap(num1, num2);
    }
    for(int i=0; i<num1.size(); i++){
        // 48 -> '0' in ascii code
        int sum = carry + (num1[i] - 48) + (num2[i] - 48);
        carry = sum / 10;
        ans += (sum % 10 + 48);
    }
    for(int i=num1.size(); i<num2.size(); i++){
        int sum = carry + (num2[i] - 48);
        carry = sum / 10;
        ans += (sum % 10 + 48);
    }
    if(carry){
        ans += carry + 48;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
//int main(){
//    string string1 = "691";
//    string string2 = "711";
//    string ans = addStrings(string1, string2);
//    cout << ans << endl;
//}