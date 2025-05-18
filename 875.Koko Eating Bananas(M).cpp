#include <cmath>
#include <vector>
using namespace std;

/**
 * My Method
 * In a brute froce way, we know it will at least take len(pile) of hours to finish, and the k will be max(piles)
 * and the min. of k will be 1, so if will iterate k from 1 - max(piles), we will eventually find the minium k that takes h hours
 *
 * Optimize
 * we know we need to iterate k from 1 - max(piles), then the optimize way will be binary search way to iterate
 * if the h[i] calc fom k[i] is less than h, that means we can still find k[j], where j < i
 * if h[i] is bigger than h, that means we need to find bigger k
 * the binary search here needs to iterate all the k, since even we find the h[i] == h
 * we may still find k[j], where j < i, that h[j] == h
 *
 * Ex: [3,6,7,11], h = 8
 * ans: 4
 *
 * Time: O(log(max(piles))* N), N is len(piles)
 * Space: O(1)
 *
 * Edge:
 * must be carful with int calcluation, constraints is piles[i] <= 10^9, it will may be overflow
 * ceil()
 */

long cal_hours(vector<int> &piles, int k)
{
    long total = 0;
    for (int &pile : piles)
    {
        total += static_cast<int>(ceil(static_cast<double>(pile) / k)); // Be careful with ceil(), if you use int divide you will only get int
    }
    return total;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1, right = *max_element(piles.begin(), piles.end());
    int ans = INT_MAX;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        int hours = cal_hours(piles, middle);

        if (hours <= h)
        {
            ans = min(ans, middle);
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return ans;
}