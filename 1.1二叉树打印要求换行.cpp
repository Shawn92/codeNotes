/*有一棵二叉树，请设计一个算法，按照层次打印这棵二叉树。

给定二叉树的根结点root，请返回打印结果，结果按照每一层一个数组进行储存，所有数组的顺序按照层数从上往下，且每一层的数组内元素按照从左往右排列。保证结点数小于等于500。
*/


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreePrinter {
public:
	vector<vector<int> > printTree(TreeNode* root) {
		// write code here
		vector<vector<int>> res;
		queue<TreeNode*> queueToPrint;
		if (root == NULL)
			return res;
		queueToPrint.push(root);

		TreeNode *last = root;
		TreeNode* nlast;
		if (root->right != NULL) nlast = root->right;
		else if (root->left != NULL) nlast = root->right;
		else nlast = NULL;
		
		vector<int> temp;
		while (!queueToPrint.empty()){
			if (queueToPrint.front()->left != NULL) 
				queueToPrint.push(queueToPrint.front()->left);
			if (queueToPrint.front()->right != NULL)
				queueToPrint.push(queueToPrint.front()->right);
			nlast = queueToPrint.back();

			temp.push_back(queueToPrint.front()->val);
			if (queueToPrint.front() == last) {
				res.push_back(temp);
				temp.erase(temp.begin(), temp.end());
				last = nlast;
			}
			queueToPrint.pop();
		}

		return res;
	}
};