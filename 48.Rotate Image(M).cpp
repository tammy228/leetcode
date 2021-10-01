#include <iostream>
#include <vector>
using namespace std;

// My Solution
//void rotate(vector<vector<int>>& matrix) {
//    int n = matrix.size();
//    for(int i=0; i<n ; i++){
//        vector<int> tmp;
//        for(int j=n-1; j>=0; j--)
//            tmp.insert(tmp.end(), matrix[j][i]);
//        matrix.insert(matrix.end(),tmp);
//    }
//    for(int i=n-1; i>=0; i--)
//        matrix.erase(matrix.begin()+i);
//}

// Optimize
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose
    for(int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    // Reverse row
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n/2; j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n-1-j];
            matrix[i][n-1-j] = tmp;
        }
    }
}