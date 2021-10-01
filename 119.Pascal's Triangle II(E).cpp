#include <iostream>
#include <vector>
using namespace std;
vector<int> getRow(int rowIndex) {
    if(rowIndex == 0)
        return {1};
    else if(rowIndex == 1)
        return {1, 1};
    else {
        vector<int> row={1, 1};
        vector<int> ans={1, 1};
        while(row.size() <= rowIndex) {
            for (int i = 1; i < row.size(); i++) {
                ans[i] = row[i - 1] + row[i];
            }
            ans.push_back(1);
            row = ans;
        }
        return ans;
    }
}

//int main(){
//    int row = 5;
//    vector<int> ans = getRow(row);
//    for(int & an : ans)
//        cout << an;
//}
