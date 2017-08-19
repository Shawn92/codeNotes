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
    //1、定义一个栈nodeStack，将root节点压入栈中
	//2、如果栈nodeStack不为空，则从栈中弹出一个节点，同时
	//   将栈顶节点cur的右孩子和左孩子依次压入栈中
	//3、弹出节点执行打印操作
    vector<int> pre_order(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        vector<int> preOrder;
        if (!root)
            return preOrder;
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            TreeNode* cur = nodeStack.top();
            preOrder.push_back(cur->val);
            nodeStack.pop();
            if (cur->right) nodeStack.push(cur->right);
            if (cur->left) nodeStack.push(cur->left);
        }
        return preOrder;
    }
    
	//1、定义一个栈nodeStack，定义一个节点指针cur，初始时cur指向root
	//2、如果cur不为空，则将cur压入栈中，同时cur指向其左孩子
	//3、如果cur为空，则将栈顶元素设置为cur并打印cur的值，之后cur指向
	//   cur的右孩子，接着执行步骤2
    vector<int> in_order(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        vector<int> inOrder;
        TreeNode* cur = root;
        while (!nodeStack.empty() || cur) {
            if (cur) {
                nodeStack.push(cur);
                cur = cur->left;
            }
            else{
                cur = nodeStack.top();
                inOrder.push_back(cur->val);
                cur = cur->right;
                nodeStack.pop();
            }
        }
        return inOrder;
    }
    
	//1、定义连个栈S1和S2，将root节点压入S1中
	//2、如果S1不为空，则从S1中弹出一个节点cur，并将cur压入S2中，
	//   同时将cur的左孩子和右孩子依次压入S1中，一直循环到S1为空
	//3、从S2中依次弹出节点并打印
    vector<int> post_order(TreeNode* root){
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> postOrder;
        if (!root) return postOrder;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode* cur = s1.top();
            s2.push(cur);
            s1.pop();
            if (cur->left) s1.push(cur->left);
            if (cur->right) s1.push(cur->right);
        }
        while (!s2.empty()) {
            postOrder.push_back(s2.top()->val);
            s2.pop();
        }
        return postOrder;
    }
    
    vector<vector<int> > convert(TreeNode* root) {
        // write code here
        vector<vector<int>> orders;
        vector<int> preOrder = pre_order(root);
        vector<int> inOrder = in_order(root);
        vector<int> postOrder = post_order(root);
        
        orders.push_back(preOrder);
        orders.push_back(inOrder);
        orders.push_back(postOrder);
        return orders;
    }
};