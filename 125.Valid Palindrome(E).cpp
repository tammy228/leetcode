#include<string>
#include<vector>
#include<cmath>
using namespace std;
/*
 * My Solution
 * 1. convert input to all alphanumeric string.(erase space, comma, change upper case to lower case)
 * 2. use two pointer, left and right, scanning the string from begin and end, at the same time.
 * 3. during the scanning, compare if it's same char.
 *
 * Edge Case:
 * 1. after converting, if it's empty, or one element.  return true;
 *
 * Missing Part:
 * 1. The while loop is base on "alphanumeric" size not "s" size
 *
 * Time: O(n)
 * Space: O(n)
 */
//bool isPalindrome(string s) {
//    string alphanumeric = "";
//    for(char ch : s){
//        // upper case
//        if(ch >= 65 && ch <= 90)
//            alphanumeric.push_back(ch+32);
//        // lower case and number
//        if((ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57))
//            alphanumeric.push_back(ch);
//    }
//    int left = 0, right = alphanumeric.size()-1;
//    // Edge case
//    if(alphanumeric.size() <= 1) return true;
//    while(left <= ceil(alphanumeric.size()/2)){
//        if(alphanumeric[right] != alphanumeric[left])
//            return false;
//        left++;
//        right--;
//    }
//    return true;
//}
/*
 * Optimize
 * 1. Use one iteration to do converting and comparing
 *
 * Edge Case:
 * 1. input size empty, return true
 * Time: O(n)
 * Space: O(1)
 */
bool isPalindrome(string s) {
    if(s.empty())  return true;
    int left = 0, right = s.size()-1;
    while(left <= right){
        if(!isalnum(s[left]))
            left++;
        else if (!isalnum(s[right]))
            right--;
        // if condition comes here, which means s[left] and s[right] are all alphanumeric
        else if(tolower(s[left]) == tolower(s[right])){
            left++;
            right--;
        }
        else
            return false;
    }
    return true;
}