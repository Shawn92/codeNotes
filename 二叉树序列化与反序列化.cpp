vector<string> spilit(string str, char ch) {
	vector<string> res;
	string temp = "";
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == ch) {
			res.push_back(temp);
			temp = "";
		}
		else
			temp += str[i];
	}
	if (temp.size() > 0)
		res.push_back(temp);
	return res;
}
TreeNode* construct(vector<string>& spilitedStr) {
	if (spilitedStr.size() > 0) {
		string val = spilitedStr[0];
		spilitedStr.erase(spilitedStr.begin());
		if (val == "#")
			return NULL;
		TreeNode* newNode = new TreeNode(atoi(val.c_str()));
		newNode->left = construct(spilitedStr);
		newNode->right = construct(spilitedStr);
		return newNode;
	}
}
//反序列化函数
TreeNode* Deserialize(string str) {
	if (str.size() == 0)
		return NULL;
	vector<string> spilitedStr = spilit(str, '!');
	return construct(spilitedStr);
}
//序列化函数
string Serialize(TreeNode *root) {
	char *p;
	string PreOrderString = "";
	stack<TreeNode*> s;
	if (root == NULL)
		return PreOrderString;
	s.push(root);
	while (!s.empty()) {
		TreeNode* curr = s.top();
		s.pop();
		if (curr) {
			PreOrderString += (to_string(curr->val) + "!");
			s.push(curr->right);
			s.push(curr->left);
		}
		else
			PreOrderString += "#!";
	}
	return PreOrderString;
}