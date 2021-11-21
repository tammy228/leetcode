#include<iostream>
#include<vector>
using namespace std;
/*
 * My Solution
 * 1. find which row it would be by iterate the row find the row which is bigger than the target.
 * 2. Apply binary search to that row.
 * Edge Case:
 *  (1) In 1. if the first elements are all smaller than target.
 *  (2) Only one element in array.
 */
bool binarySearch(vector<int>& nums, int target){
    int left=0, right=nums.size()-1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(target > nums[middle])
            left = middle + 1;
        else if(target < nums[middle])
            right = middle - 1;
        else{
            return true;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // 1.
    int row = -1;
    for(int i=0; i<matrix.size(); i++){
        if(matrix[i][0] > target){
            row = i-1;
            break;
        }
    }
    // Edge Case
    if(row == -1){
        if(target <= matrix[matrix.size()-1][matrix[matrix.size()-1].size()-1])
             return binarySearch(matrix[matrix.size()-1], target);
        else
            return false;
    }else
         return binarySearch(matrix[row], target);
}
//int main(){
//    vector<vector<int>> nums = {{1}};
//    bool ans = searchMatrix(nums, 0);
//    cout << ans << endl;
//}