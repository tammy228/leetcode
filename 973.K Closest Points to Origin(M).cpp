#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

/*
 * My Solution
 * 1. 計算出每個vector 的距離
 * 2. 用 map 紀錄距離跟vector的關係
 * 3. sort 距離
 * 4. output k closest vector
 *
 * Time:
 * O(N): where N == points.size()
 *
 * Space:
 * O(N): where N == points.size()
 *
 */
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    unordered_map<int, vector<vector<int>>> map;
    vector<int> dis;
    vector<vector<int>> result;
    for(int i=0; i<points.size(); i++){
        int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        dis.push_back(distance);
        map[distance].push_back(points[i]);
    }

    sort(dis.begin(), dis.end());

    for(int i=0; i<k; i++){
        vector<vector<int>> vec = map[dis[i]];
        for(auto ele : vec){
            result.push_back(ele);
            if(k == result.size())
                return result;
        }
    }

    return result;
}
/*
 * Optimize
 * *(Should use MaxHeap not MinHeap)
 * cause MinHeap need to store all element, while MaxHeap only need to store k element.
 * As soon as MaxHeap size reach over k, we just pop root out
 *
 * Time:
 * O(N * logK): since there are k elements in heap, pop take O(logK), and arrays contains N elements
 *
 * Space:
 * O(K): maxHeap size
 */

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    vector<vector<int>> result;


    for (auto& p : points) {
        int x = p[0], y = p[1];
        maxHeap.push({(x*x) + (y*y),{x,y}});
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    for (int i = 0; i < k; ++i) {
        pair<int,int> p = maxHeap.top().second;
        result.push_back({p.first,p.second});
        maxHeap.pop();
    }

    return result;
}