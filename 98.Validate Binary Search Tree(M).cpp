#include <stack>
#include <climits>
using namespace
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
 * Use DFS to traverse whole tree, while traversing use lower bound and upper bound to compare
 *
 * Time:
 * O(n) -> traverse all node
 *
 * Space:
 * O(1)
 */
bool dfs(TreeNode* node, long lower_bound, long upper_bound){
    if(!node)
        return true;
    if(node->val >= upper_bound || node->val <= lower_bound)
        return false;

    bool left = dfs(node->left, lower_bound, long(node->val));
    bool right = dfs(node->right, long(node->val), upper_bound);
    return left && right;


    // Tidy Version but not faster
//    if(!node)
//        return true;
//    // Since it's a BST there is going to be left and right node or null node
//    if(node->val >= upper_bound || node->val <= lower_bound)
//        return false;
//    return dfs(node->left, lower_bound, long(node->val)) && dfs(node->right, long(node->val), upper_bound);
}

bool isValidBST(TreeNode* root) {
    return dfs(root, LONG_MIN, LONG_MAX);
}