#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int dfs(TreeNode* root){
    if(root == NULL)
        return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    return max(left, right)+1;


}
int maxDepth(TreeNode* root) {

    return dfs(root);
}