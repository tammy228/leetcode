#include <iostream>
#include <vector>
using namespace std;

// My Solution O(m*log(n))
//bool binary_search(vector<int>& array, int target){
//    int i = 0;
//    int j = array.size()-1;
//    while(i<=j){
//        int middle = (j+i) / 2;
//        if(target == array[middle]) return true;
//        else if(target > array[middle])  i = middle + 1;
//        else j = middle - 1;
//    }
//    return false;
//}
//
//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//    int row = matrix.size();
//    int col = matrix[0].size();
//    bool ans = false;
//    for(int i=0; i<row; i++){
//        if(target >= matrix[i][0] && target <= matrix[i][col-1]) {
//            ans = binary_search(matrix[i], target);
//            if (ans) break;
//        }
//    }
//    return ans;
//}
// Optimize
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // if we consider the upper right corner
    // from that position if we see the values below it are increasing while values left to it are decreasing,
    // so we use this to find our solution
    int row = matrix.size();
    int col = matrix[0].size();
    int i=0;
    int j = col-1;
    while(i<row && j>=0){
        if(matrix[i][j] == target)
            return true;
        else if(matrix[i][j] > target) j--;
        else i++;
    }
    return false;
}