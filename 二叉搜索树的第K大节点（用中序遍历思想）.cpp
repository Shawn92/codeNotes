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
    TreeNode* KthNode(TreeNode* pRoot, int k)//中序遍历
    {
        int cnt = 0;
        return KthNode(pRoot, k, cnt);
    }
    //使用中序遍历的思想
    TreeNode* KthNode(TreeNode* pRoot, int k, int &cnt)
    {
        if (pRoot == NULL) {
            return NULL;
        }
        TreeNode* left = KthNode(pRoot->left, k, cnt);//先在左子树中找
        if (left != NULL) {
            return left;
        }
        ++cnt;
        if (cnt == k) {
            return pRoot;
        }
        //在右子树中找
        return KthNode(pRoot->right, k, cnt);
    }
};