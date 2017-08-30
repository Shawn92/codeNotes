/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class IdenticalTree {
public:
    void DFSPrint (TreeNode* root, string& path) {
        if (root == NULL)
            path += "#!";
        else {
            path += to_string(root->val);
            path += "!";
            DFSPrint(root->left, path);
            DFSPrint(root->right, path);
        }
    }
    
    bool chkIdentical(TreeNode* A, TreeNode* B) {
        // write code here
        string str1 = "", str2 = "";
        DFSPrint(A, str1);
        DFSPrint(B, str2);
        return str1.find(str2) != string::npos;
    }
};