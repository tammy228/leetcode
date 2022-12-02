#include<vector>
using namespace std;
/*
 * My Solution
 * 從 root 開始找，直到p,q 分別是左右child，若其中有一個是另個的ancestor就直接輸出該ancestor
 * 因為是BST，所以左右child 就一定會是一個大於root 一個小於root
 *
 * Time:
 * O(logn): cause of BST height
 *
 * Space:
 * O(1)
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL){
            if(p->val > root->val && q->val > root->val){
                root = root->right;
            }else if(p->val < root->val && q->val < root->val){
                root = root->left;
            }else{
                return root;
            }
        }
        return root;
    }
};