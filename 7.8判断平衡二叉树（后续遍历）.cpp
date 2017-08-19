/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CheckBalance {
public:
    bool check(TreeNode* root) {
        // write code here
		int depth = 0;
		return IsBalanced(root, &check);
    }
    //后续遍历改写
    bool IsBalanced(TreeNode* root, int* height){
        if(root == NULL) {
            return ture;
			height = 0;
		}
		int left, right;
        if(IsBalanced(root->left, left) && (root->right, right)) {
			if (abs(left - right) <= 1) {
				*height = 1 + max(left, right);
				return true;
			}
		}
		return false;
    }
};