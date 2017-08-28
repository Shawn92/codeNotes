/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL)
            return left == right;
        if (left->val == right ->val)
            return isSymmetrical(left->right, right->left) && isSymmetrical(left->left, right->right);
        return false;
    }
    
    bool isSymmetrical(TreeNode* pRoot){
        if (pRoot == NULL)
            return true;
        return isSymmetrical(pRoot->left, pRoot->right);
    }

};