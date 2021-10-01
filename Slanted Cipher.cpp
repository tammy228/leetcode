#include <iostream>
#include <vector>
using namespace std;
string decode(int numberRows, string encodedString){
    int n = encodedString.size();
    int gap = n / numberRows;
    int index = 0;
    string ans = "";
    while(true){
        for(int i=0; i<numberRows; i++){
            cout << index;
            if(gap*i+ (index+i) >= n) break;
            else ans += encodedString[gap*i + (i+index)] == '_' ? '!' : encodedString[gap*i + (i+index)];
        }
        if(gap*(numberRows-1) + (index+numberRows-1) >= n) break;
        index++;
    }
    return ans;
}
//int main(){
//    string test = "mnes__ya_____mi";
//    string ans = decode(3, test);
//    cout << ans;
//}
