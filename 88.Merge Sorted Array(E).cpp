#include<vector>
using namespace std;

/*
 * My Solution
 * 1. iterate nums2, and compare the number in nums1.(There will be two index)
 *    if nums2[id2] > nums1[id1] then id1++
 *    else nums1.insert(it+id1, nums2[id2])
 * 2. After iteration, pop all zero out of nums1.
 *
 *
 * Edge Case:
 * 1. nums2 are empty, then return nums1
 *
 * Missing Part:
 * 1. missing understanding of the last element of 0. -> Change the code to pop last n times of 0.
 * 2. Line 23: index1++ will cause index out of bound. -> Add restraint to index1
 *
 * Time: O(n+m)
 * Space: O(1)
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n != 0){
        int index1 = 0;
        for(int index2=0; index2<n; index2++){
            while(nums2[index2] > nums1[index1] && index1 < m+index2) index1++;
            nums1.insert(nums1.begin()+index1, nums2[index2]);
        }
        while(nums1.back() == 0 && n != 0){
            nums1.pop_back();
            n--;
        }
    }
}