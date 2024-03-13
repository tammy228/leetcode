#include <vector>
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
 * use level traversal
 * for each level traverse right to left, store first element to ans
 */
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    queue<TreeNode*> q;
    if (root)   q.push(root);
    int level = 0;
    while(!q.empty())
    {
        bool pushed = false;
        int level_size = q.size();
        for(int i=0; i<level_size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if (node->right)    q.push(node->right);
            if (node->left)     q.push(node->left);
            if(!pushed)
            {
                ans.push_back(node->val);
                pushed = true;
            }
        }
        level++;
    }
    return ans;
}