#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    if(n == 1)
        return {{1}};
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int num = 1;
    int index = n-1;
    int tmp = 0;
    // ➡︎
    for(int k = 0; k < n/2; k++){
        int j;
        for (k<=1 ? j = 0 : j = k-1; j <= index+tmp; j++) {
            ans[k][j] = num;
            if(j<index+tmp)
                num+=1;
        }

        if(k == 0) {
            num = num + (index * 2) + (index - 1);
            index -= 1;
        }
        else {
            num = num + ((index-1) * 2) + index-2;
            index -= 2;
            tmp++;
        }

    }
    // ⬇︎
    index = n-1;
    num = n;
    tmp = 0;
    for(int k = n-1; k >= n/2; k--){
        for (int j = 0+tmp; j <= index+tmp; j++) {
            ans[j][k] = num;
            if(j<index+tmp)
                num+=1;
        }

        num = num + index + (index - 1) * 2;

        index-=2;
        tmp+=1;
    }
    // ⬅
    index = n-1;
    num = n*2-1;
    tmp = 0;
    for(int k = n-1; k >= n/2; k--){

        for (int j = index+tmp; j >= 0+tmp; j--) {
            ans[k][j] = num;
            if(j>0+tmp)
                num+=1;
        }
        num = num + (index - 1) * 2 + index-2 ;

        index-=2;
        tmp+=1;
    }
    // ⬆︎︎
    index = n-1;
    num = n*3-2;
    tmp = 0;
    for(int k = 0; k <= n/2; k++){
        for (int j = index+tmp; j >= 1+tmp; j--) {
            ans[j][k] = num;
            if(j>1+tmp)
                num+=1;
        }

        num = num + (index - 2) * 2 + index-1 ;

        index-=2;
        tmp+=1;
    }
    return ans;
}

//int main(){
//    vector<vector<int>> test = generateMatrix(8);
//    for(auto IE=test.begin(); IE!=test.end(); IE++) {
//        for (auto it = (*IE).begin(); it != (*IE).end(); it++) {
//            cout << *it << "  ";
//        }
//        cout << "\n";
//    }
//}