#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
 * My Solution
 * Use BFS(queue) to do level traversal
 * Be careful with the null node, it can be pushed into queue, but we don't want it in our result
 *
 * Time:
 * O(N): visiting every node one time
 *
 * Space:
 * O(N): queue will only store up to N/2 size, because of binary tree
 */
void levelTraversal(vector<vector<int>> &result, queue<TreeNode* > q){
    while(!q.empty()){
        int level = q.size();
        vector<int> levelItem;
        for(int i=0; i<level; i++){
            TreeNode* curr = q.front();
            q.pop();
            if(curr){
                levelItem.push_back(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        // Make sure not store null node
        if(levelItem.size() != 0)
            result.push_back(levelItem);
    }
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode* > q;
    q.push(root);
    levelTraversal(result, q);
    return result;
}