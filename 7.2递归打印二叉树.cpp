/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreeToSequence {
public:
    void pre_order(TreeNode* root, vector<int>& preOrder) {
        if (!root)
            return;
        preOrder.push_back(root->val);
        pre_order(root->left, preOrder);
        pre_order(root->right, preOrder); 
    }
    
    
    void in_order(TreeNode* root, vector<int>& inOrder) {
        if (!root)
            return;
        in_order(root->left, inOrder);
        inOrder.push_back(root->val);
        in_order(root->right, inOrder);
    }
    
    
    void post_order(TreeNode* root, vector<int>& postOrder) {
        if (!root)
            return;
        post_order(root->left, postOrder);
        post_order(root->right, postOrder);
        postOrder.push_back(root->val);
    }
    
    vector<vector<int> > convert(TreeNode* root) {
        // write code here
        vector<vector<int>> orders;
        vector<int> preOrder;
        vector<int> inOrder;
        vector<int> postOrder;
        pre_order(root, preOrder);
        in_order(root, inOrder);
        post_order(root, postOrder);
        orders.push_back(preOrder);
        orders.push_back(inOrder);
        orders.push_back(postOrder);
        return orders;
    }
};