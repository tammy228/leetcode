using namespace std;
/*
 * My Solution
 * The whole concept is to use binary search, and use it to search the whole array.
 *
 * Edge Case:
 * 1. Since int n is the INT_MAX, so we can not use '+' to do find the middle.
 *
 * Time:
 * O(logn)
 *
 * Space:
 * O(1)
 */
int firstBadVersion(int n) {
    int left=1, right=n;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(isBadVersion(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}