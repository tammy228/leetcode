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
 * 找每個 node 的左子樹跟右子樹的 "height和", 然後再去keep track of diameter
 *
 * Time:
 * O(N)
 *
 * Space:
 * O(N): recursive calls
 */
int dfs(TreeNode* node, int& diameter){
    if(node == nullptr)
        return 0;
    int left_height = dfs(node->left, diameter);
    int right_height = dfs(node->right, diameter);
    diameter = max(diameter, left_height+right_height);

    return max(left_height, right_height)+1;
}
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    dfs(root, diameter);
    return diameter;
}