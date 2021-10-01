#include <vector>
#include <iostream>
using namespace std;
int maxPresentation(int num, vector<int>& begin, vector<int>& end){
    vector<vector<int>> pair;
    int count = 1;
    for(int i=0; i<begin.size(); i++){
        pair.insert(pair.end(), {begin[i], end[i]});
    }
    sort(pair.begin(), pair.end());

    int pointer_x = pair[0][0];
    int pointer_y = pair[0][1];
    for(int i=1; i<pair.size(); i++){
        if(pair[i][0] >= pointer_y){
            count ++;
            pointer_x = pair[i][0];
            pointer_y = pair[i][1];
        }else{
            if(pair[i][1]-pair[i][0] < pointer_y-pointer_x){
                pointer_x = pair[i][0];
                pointer_y = pair[i][1];
            }
        }
    }
    return count;
}
//int main(){
//    int num = 3;
//    vector<int> begin = {1,1,2};
//    vector<int> end = {3,2,4};
//    int ans = maxPresentation(num, begin, end);
//    cout << ans << endl;
//}

