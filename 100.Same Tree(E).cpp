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
 */
//bool traverse(TreeNode* p, TreeNode* q, bool& result){
//    if(p == nullptr && q == nullptr){
//        if(result)
//            return true;
//        else
//            return false;
//    }
//    if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)){
//        result = false;
//        return false;
//    }
//    if((p->val != q->val)){
//        result = false;
//    }
//
//    traverse(p->left, q->left, result);
//    traverse(p->right, q->right, result);
//
//    if(result == true)
//        return true;
//    else
//        return false;
//}
//
//bool isSameTree(TreeNode* p, TreeNode* q) {
//    bool result = true;
//    return traverse(p,q, result);
//}

/*
 * Optimize
 *
 * Turn above code to more tidy
 */
bool traverse(TreeNode* p, TreeNode* q){
    if(p == nullptr && q == nullptr)
        return true;
    if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
        return false;

    if((p->val != q->val)){
        return false;
    }

    bool left_res = traverse(p->left, q->left);
    bool right_res = traverse(p->right, q->right);

    if(left_res && right_res)
        return true;
    else
        return false;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return traverse(p,q);
}
