#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countOnes(int number){
    int count = 0;
    while(number){
        if(number & 1)
            count ++;
        number = number >> 1;
    }
    return count;
}

// Use 32bit二維 to store : O(N^2logN)
//vector<int> bitCountSort(vector<int> arr){
//    vector<vector<int>> ones(32);
//    vector<int> ans;
//    for(int i=0; i<arr.size(); i++){
//        int tmp = countOnes(arr[i]);
//        ones[tmp].insert(ones[tmp].end(), arr[i]);
//    }
//
//    for(int i=31; i>=0; i--){
//        int n = ones[i].size();
//        if( n != 0) {
//            if(n != 1) {
//                sort(ones[i].begin(), ones[i].end());
//                for (int j : ones[i])
//                    ans.insert(ans.end(), j);
//            }else
//                ans.insert(ans.end(), ones[i][0]);
//        }
//    }
//    return ans;
//}


int partition(vector<int>& arr, int left, int right){
    int pivot_bit = countOnes(arr[right]);
    int pivot = arr[right];
    int p_index = left;
    for(int i=left; i<right; i++){
        int arr_bit = countOnes(arr[i]);
        if(arr_bit < pivot_bit) {
            int tmp = arr[i];
            arr[i] = arr[p_index];
            arr[p_index] = tmp;
            p_index++;
        }
        if(arr_bit == pivot_bit && arr[i] > pivot){
            int tmp = arr[i];
            arr[i] = arr[p_index];
            arr[p_index] = tmp;
            p_index++;
        }
    }
    int tmp = arr[p_index];
    arr[p_index] = arr[right];
    arr[right] = tmp;
    return p_index;
}
void quicksort(vector<int>& arr, int left, int right){
    if(left < right){
        int p_index = partition(arr, left, right);
        quicksort(arr, 0, p_index-1);
        quicksort(arr, p_index+1, right);
    }
}
// QuickSort Implementation
vector<int> bitCountSort(vector<int> arr) {
    quicksort(arr, 0, arr.size()-1);
    return arr;
}

//int main(){
//    vector<int> test = {5, 2, 3, 9, 4, 6, 7, 15, 32};
//    vector<int> final = bitCountSort(test);
//    for(int i=final.size()-1; i>=0; i--)
//        cout << final[i] << " ";
//}
