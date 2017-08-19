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