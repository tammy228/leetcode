#include<vector>
using namespace std;
/*
 * My Solution
 * DFS
 * 問題的本質就是看到node swap 他們的children, 然後再繼續往子樹下去
 *
 * Time:
 * O(n) n for all node in tree.
 *
 * Space:
 * O(n) we didn't use extra space, but in call stack will use n element to do DFS.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* invertTree(TreeNode* root) {
    if(root == NULL)
        return root;

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
    return root;
}