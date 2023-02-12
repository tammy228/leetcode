#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 * My Solution
 * Common Ancestor: means that the subtree of the node contain p and q
 * Lowest Common Ancestor : means the first found node if we use dfs
 *
 * Time:
 * O(N)
 *
 * Space:
 * O(N)
 */
int dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &result){
    if(root == NULL) return 0;

    int left = dfs(root->left, p, q, result);
    int right = dfs(root->right, p, q, result);
    int self = (root == q) || (root == p) ? 1 : 0;

    int count = left+right+self;
    if(count == 2 && result == NULL)
        result = root;

    return count;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* result = NULL;
    int _ = dfs(root, p, q, result);
    return result;
}