#include <iostream>
#include <vector>
using namespace std;
/*
 * My Solution
 * (Bucket Sort)
 * Basically create n buckets, and count how many times does it occur
 * After that, put the number into the origin array
 */
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int red=0,white=0,blue=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0)
            red++;
        else if(nums[i] == 1)
            white++;
        else
            blue++;
    }
    for(int i=0; i<nums.size(); i++)
        if(i<red)
            nums[i] = 0;
        else if(i < red+white)
            nums[i] = 1;
        else
            nums[i] = 2;

}
/*
 * Optimize
 * (Quick Sort partition)
 * Use left/right index, and pivot if pivot is 0 swap it to left, and if it is 2 swap it to right
 */
void sortColors(vector<int>& nums) {
    int left=0, right=nums.size()-1, index=0;
    while(index <= right){
        if(nums[index] == 0) {
            swap(nums[left], nums[index]);
            left++;
        }
        if(nums[index] == 2){
            swap(nums[right], nums[index]);
            right--;
            // The reason why decrement index is because, after swapping right, it might be 0,
            // Therefor, we need to check left side again.
            index--;
        }
        index++;
    }
}

