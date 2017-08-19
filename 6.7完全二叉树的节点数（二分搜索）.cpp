/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CountNodes {
public:
    int count(TreeNode* root) {
        // write code here
        if (!root->right)
            return 1;
        
        TreeNode* p = root;
        int leftHeight = 0, rightHeight = 0;
        p = p->left;
        while (p){
            p = p->left;
            ++leftHeight;
        }
        p = root->right;
        while (p){
            p = p->left;
            ++rightHeight;
        }
        
        if (leftHeight == rightHeight){
            //如果左子树是满的
            return pow(2, leftHeight) + count(root->right);
    	}
        else if(leftHeight > rightHeight) {
            //如果右子树是满的
            return pow(2, rightHeight) + count(root->left);
        }
        return 0;
    }
};