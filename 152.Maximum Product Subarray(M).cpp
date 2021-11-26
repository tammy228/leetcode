#include<vector>
#include<iostream>
using namespace std;
/*
 * My Solution
 * *
 * 1. iterate array and store biggest(left-> right , right-> left)
 * 2. if element == 0
 *    重新連乘
 *
 * Time: O(n)
 *
 * Edge Case:
 * 1. Contain zeros: 把連乘值變1
 */
int maxProduct(vector<int>& nums) {
    int product=1;
    int ans = INT_MIN;
    if(nums.size() == 1) return nums[0];
    for(int i=0; i<nums.size(); i++){
        product *= nums[i];
        ans = max(ans, product);
        if(product == 0) product = 1;
    }
    product = 1;
    for(int i=nums.size()-1; i>=0; i--){
        product *= nums[i];
        ans = max(ans, product);
        if(product == 0) product = 1;
    }
    return ans;
}

