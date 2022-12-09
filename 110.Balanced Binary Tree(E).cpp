#include <vector>
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
 * Use dfs to keep track of every nodes' height
 * As soon as finding imbalance, it will all be imbalance during dfs
 *
 * Time:
 * O(N): since we need to check up on every node
 *
 * Space:
 * O(N): ideal tree would be O(logN), because it will be stacked up logN times in the stack.
 *       if it's skewed tree, it will be O(N)
 */
int dfs(TreeNode* root){
    // leaf node
    if(!root)
        return 0;

    int leftHeight = dfs(root->left);
    int rightHeight = dfs(root->right);

    if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;

}

bool isBalanced(TreeNode* root) {
    if(dfs(root) == -1)
        return false;
    return true;
}